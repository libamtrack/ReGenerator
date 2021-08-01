"""
Header parser - this script takes a path to a C header file and writes
an R wrapper for functions defined inside. It currently supports returning
a value via parameters, but not with a return statement

Here are examples of what inputs are and aren't accepted by the regexes below
>>> bool(param_regex.fullmatch('@param n'))
True
>>> bool(param_regex.fullmatch('@param[in] _number_of_items'))
True
>>> bool(param_regex.fullmatch('\\param[out] res1    result of the function'))
True
>>> bool(param_regex.fullmatch('\\param[in,out] temp__    temperature measurements before and afer (array of length 14)'))
True
>>> bool(param_regex.fullmatch('@param names    names of searched people (array of size number_of_people)'))
True
>>> bool(param_regex.fullmatch('@param 5tomatoes'))
False
>>> bool(param_regex.fullmatch('param[out] res2  result of another function'))
False

>>> bool(array_regex.fullmatch('array of length 15'))
True
>>> bool(array_regex.fullmatch('array of size   number_of_buckets'))
True
>>> bool(array_regex.fullmatch('array of length -5'))
False
"""

import re
import argparse
import ctypes  # used in eval
import warnings
from sys import stderr
from pathlib import Path
from collections.abc import Collection
from typing import Union

from CppHeaderParser import CppHeader, CppMethod, CppVariable

from ctype_translator import mapping


#  This regex matches a doxygen description of a parameter, including:
#  - its access mode (whether it's in/out/in,out)
#  - its name (docstring requires parameter name, function definition doesn't)
param_regex = re.compile(
    r"""
    [@\\]param                       # PROPER parameter classifier
    (?P<mode>(\[(in|out|in,\s*out)])?)  # parameter may be in, out, both or unspecified (in by default)
    \s*
    (?P<name>[a-z_][a-z0-9_]*)       # won't match C99's unicode names
    .*$                              # also capture the description
    """, re.VERBOSE | re.MULTILINE | re.IGNORECASE
)

#  This regex searches for matches the phrase 'array of length/size ___'
#  and retrieves the last term (a number or a name) to use for setting
#  or checking length in the wrapper.
array_regex = re.compile(r'array\s*of\s*(length|size)\s*(?P<lname>[a-z0-9_]+)')


def extract_functions_from_file(path) -> list[CppMethod]:
    try:
        return CppHeader(path).functions
    except IOError:
        raise
    except (TypeError, ValueError, AttributeError) as e:
        message = f'{path} is not a valid C/C++ header file'
        raise ValueError(message) from e


class Parameter:
    def __init__(self,
                 desc: CppVariable,
                 ordinal: int,
                 mode: str,
                 size: str = None):
        self.ord = ordinal
        self.type = mapping[eval(desc['ctypes_type'])]
        self.name = desc['name']
        self.mode = mode[1:-1].lower() if mode != '' else 'in'
        self.size = size
        self.targets = []  # only used with size parameters
        if size:
            try:
                if size.startswith('0x'):
                    self.size = int(size, 16)
                elif size[0] == '0':
                    self.size = int(size, 8)
                else:
                    self.size = int(size)

            except ValueError:
                if size[0].isnumeric():
                    message = (
                        f'{size} is neither a variable '
                        'name nor a numeric literal'
                    )
                    raise ValueError(message)

    @property
    def conversion(self):
        return f'\t{self.name} <- as.{self.type}({self.name})'


def create_wrapper_for_function(fun: CppMethod) -> str:
    """
    Uses a function as parsed by robotpy-cppheaderparser together with its
    doxygen comment in order to create an R wrapper

    Example: the function defined as follows

    ```
    /**
     * @brief description
     * @param[in] param1
     * @param[in,out] param2 array of length param1
     * @param[out] param3 array of length param1
     */
    int some_func(const int *param1, int *param2, float *param3);
    ```

    Will produce a wrapper like this

    ```
    some.func <- function(param2){
      param1 <- max(length(param2))
      param2 <- as.integer(param2)
      param3 <- vector(mode="integer", length=param1)
      AUTO_RET_PARAMS <- .C("some_func", param1, param2, param3)
      param2 <- AUTO_RET_PARAMS$param2
      param3 <- AUTO_RET_PARAMS$param3
      AUTO_RETVAL <- list("param2" = param2, "param3" = param3
      return(AUTO_RETVAL)
    }
    ```

    :param fun: The function signature together with doxygen comment
    :type fun: CppMethod
    :return: The R wrapper for the provided C function
    :rtype: str
    :raise: :py:class:`ValueError` when the function can't be parsed
    """
    func_name = fun['name'].replace('_', '.')
    signature = [f'{func_name} <- function(']
    center = ['){']
    ending = ['\treturn(AUTO_RETVAL)', '}']
    parameter_list = []
    call_proper = f'\tAUTO_RET_PARAMS <- .C("{fun["name"]}", '
    call_params = []
    before_call = []
    after_call = []

    parameters: dict[str, Parameter] = {}
    size_parameters = set()

    # Creates a list of Parameter objects and reads whether they are in or out
    # from the doxygen. Also designates a Parameter as an array if it matches
    # `array_regex` and checks if it's a number or a defined parameter
    for param_desc, param_doxy, i in zip(
            fun['parameters'],
            param_regex.finditer(fun['doxygen']),
            range(len(fun['parameters']))
    ):
        param_mode = param_doxy.group('mode')
        array_info = array_regex.search(param_doxy.group(0))
        param_size = array_info.group('lname') if array_info else None
        try:
            param = parameters[param_desc['name']] = Parameter(
                param_desc, i, param_mode, param_size
            )
        except ValueError as e:
            message = (
                'Cannot create wrapper for function '
                '{} (defined in {})'
            ).format(fun["name"], fun["filename"])
            raise ValueError(message) from e
        if isinstance(param.size, str):
            size_parameters.add(param.size)

    list_parameters = sorted(parameters.values(), key=lambda x: x.ord)
    out_params = [p for p in list_parameters if p.mode in ['out', 'in,out']]
    if len(out_params) == 0:
        message = (
            '{} appears to have no output parameters (defined in {})'
            .format(fun["name"], fun["filename"])
        )
        warnings.warn(message)
        return ''  # no output parameters, no point in creating a wrapper
    for param in size_parameters:
        try:
            if parameters[param].mode == 'in':
                parameters[param].mode = 'size'
        except KeyError as e:
            message = (
                '{} is not a parameter of {} (defined in {}'
                .format(param, fun["name"], fun["filename"])
            )
            raise ValueError(message) from e

    for param in parameters.values():
        if isinstance(param.size, str):
            if param.mode in ['in', 'in,out']:
                parameters[param.size].targets.append(param)

    for param in size_parameters:
        before_call.append(
            '\t{} <- min({})'
            .format(param,
                    ",".join([f"length({target.name})"
                              for target
                              in parameters[param].targets]))
        )

    for param in list_parameters:
        call_params.append(param.name)
        if param.mode in ['in', 'in,out']:
            parameter_list.append('\t' + param.name)
            before_call.append(param.conversion)
            if isinstance(param.size, int):
                before_call.append(
                    f'\tstopifnot(length({param.name}) >= {param.size})'
                )
        if param.mode in ['out', 'in,out']:
            if param.mode == 'out':
                before_call.append(
                    f'\t{param.name} <- vector(mode = "'
                    f'{"double" if param.type == "single" else param.type}'
                    f'", length = {param.size if param.size else 1})'
                )
            after_call.append(
                f'\t{param.name} <- AUTO_RET_PARAMS${param.name}'
            )

    call_proper = call_proper + ', '.join(call_params) + ')'
    if len(out_params) == 1:
        after_call.append(f'\tAUTO_RETVAL <- {out_params[0].name}')
    else:
        after_call.append(
            '\tAUTO_RETVAL <- list({})'
            .format(",".join([f'"{p.name}" = {p.name}' for p in out_params]))
        )

    return '\n'.join(signature
                     + [',\n'.join(parameter_list)]
                     + center
                     + before_call
                     + [call_proper]
                     + after_call
                     + ending) + '\n\n\n'


def create_wrappers_for_header_file(path: str,
                                    out_dir: str,
                                    namespace: Collection[str] = None):
    Path(out_dir).mkdir(parents=True, exist_ok=True)
    out_path = Path(out_dir + '/' + Path(path).name.replace('.h', '.R'))
    out_strings = []
    for func in extract_functions_from_file(path):
        if namespace is None or func['name'] in namespace:
            try:
                out_strings.append(create_wrapper_for_function(func))
            except Exception as e:
                print(e, file=stderr)
    if any(out_strings):  # only create the file if there's anything to write
        try:
            # we force utf-8 encoding to avoid any strange encodings windows tends to use on some locales
            with open(out_path, 'w', encoding='utf-8') as fout:
                print('\n\n'.join(out_strings), file=fout)
        except IOError as e:
            print(e, file=stderr)


def read_namespace(path: str) -> Union[tuple[None, None], tuple[set[str], set[str]]]:
    """
    Reads the namespace project file specified by path and return functions
    for which we want to create wrappers and which we want to export.

    Function names should be one per line, optional 'noR:' at the beginning
    will indicate that we want to create a wrapper, but not export it;
    comments begin with '#'

    :param path: path to your namespace file
    :return:
    """
    try:
        # in theory we don't expect any non-ascii characters, but better safe than sorry
        with open(path, 'r', encoding='utf-8') as fin:
            names = fin.readlines()
    except IOError:
        print("Couldn't retrieve namespace, assuming all functions")
        return None, None
    names = map(lambda x: re.sub(r'#.*$', '', x).strip(), names)  # remove comments
    names = filter(None, names)  # remove empty lines
    export = set()
    wrapper = set()
    for name in names:
        if name.startswith('noR:'):
            wrapper.add(name[4:])
        else:
            wrapper.add(name)
            export.add(name.replace('_', '.'))
    return export, wrapper


def main():
    parser = argparse.ArgumentParser(
        description='Create R wrapper for functions declared in a header file(s)'
    )
    parser.add_argument('infile', nargs='+',
                        help='C header files to be parsed')
    parser.add_argument('-o', dest='out_dir', metavar='output_dir',
                        help='directory to write wrappers to, (default ./out)',
                        default='./out')
    parser.add_argument('-n', dest='namespace', metavar='namespace',
                        help='path to project namespace file (default ./NAMESPACE)',
                        default='./NAMESPACE')
    args = parser.parse_args()
    _, gen_wrapper = read_namespace(args.namespace)
    for infile in args.infile:
        create_wrappers_for_header_file(infile, args.out_dir, gen_wrapper)


if __name__ == '__main__':
    main()
