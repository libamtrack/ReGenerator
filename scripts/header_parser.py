"""
Header parser - this script takes a path to a C header file and writes
an R wrapper for functions defined inside. It currently supports returning
a value via parameters, but not with a return statement

Here are examples of what inputs are and aren't accepted by the regexes below
>>> m = param_regex.fullmatch('@param n')
>>> m is None
False
>>> m.group('mode')
''
>>> m.group('name')
'n'
>>> m.group('desc')
''

>>> m = param_regex.fullmatch('@param[in] _number_of_items')
>>> m is None
False
>>> m.group('mode')
'[in]'
>>> m.group('name')
'_number_of_items'
>>> m.group('desc')
''

>>> m = param_regex.fullmatch('\\param[out] res1    result of the function')
>>> m is None
False
>>> m.group('mode')
'[out]'
>>> m.group('name')
'res1'
>>> m.group('desc')
'result of the function'

>>> m = param_regex.fullmatch('\\param[in,out] temp__    temperature '
... 'measurements before and afer (array of length 14)')
>>> m is None
False
>>> m.group('mode')
'[in,out]'
>>> m.group('name')
'temp__'
>>> m.group('desc')
'temperature measurements before and afer (array of length 14)'

>>> m = param_regex.fullmatch('@param names    names of searched people (array of size number_of_people)')
>>> m is None
False
>>> m.group('mode')
''
>>> m.group('name')
'names'
>>> m.group('desc')
'names of searched people (array of size number_of_people)'

>>> m = param_regex.fullmatch('@param 5tomatoes')
>>> m is None
True

>>> m = param_regex.fullmatch('param[out] res2  result of another function')
>>> m is None
True


>>> m = array_regex.fullmatch('array of length 15')
>>> m is None
False
>>> m.group('lname')
'15'

>>> m = array_regex.fullmatch('array of size   number_of_buckets')
>>> m is None
False
>>> m.group('lname')
'number_of_buckets'

>>> m = array_regex.fullmatch('array of length -5')
>>> m is None
True
"""

import re
import argparse
import ctypes  # used by eval
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
    (?P<desc>.*?)$                    # also capture the description
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
                 size: str = None,
                 description: str = ""):
        self.ord = ordinal
        self.type = mapping[eval(desc['ctypes_type'])]
        self.name = desc['name']
        self.mode = mode[1:-1].lower() if mode != '' else 'in'
        self.size = size
        self.targets = []  # only used with size parameters
        self.description = description.strip()
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

    def is_out(self):
        return 'out' in self.mode

    def is_in(self):
        return 'in' in self.mode or self.mode == 'size'

    def is_size(self):
        return self.mode == 'size'

    def is_array(self):
        return self.size is not None

    @property
    def conversion(self):
        return f'\t{self.name} <- as.{self.type}({self.name})'


def parse_function_info(fun: CppMethod, abs_path: Path = None) -> tuple[str, list[Parameter], int]:
    """
    Extracts the name and parameters from a given CppMethod object

    :param fun: A CppMethod extracted by robotpy-cppheaderparser
    :param abs_path: absolute path to the header file
    :return: tuple containing the function's name, list of its parameters, line number
    """
    if abs_path is None:
        abs_path = Path(fun['filename']).absolute()
    func_name = fun['name']
    line_no = fun['line_number']
    params_list = []
    params_descriptions = list(param_regex.finditer(fun['doxygen']))

    if len(params_descriptions) != len(fun['parameters']):
        message = (
            '{}:{}: Cannot create wrapper for function {}: docstring '
            'defines {} parameters while function declaration defines {}'
        ).format(abs_path, line_no, func_name,
                 len(params_descriptions), len(fun['parameters']))
        raise ValueError(message)

    for param_desc, param_doxy, i in zip(
            fun['parameters'],
            params_descriptions,
            range(len(fun['parameters']))
    ):
        param_mode = param_doxy.group('mode')
        array_info = array_regex.search(param_doxy.group(0))
        param_size = array_info.group('lname') if array_info else None
        param_doc = param_doxy.group('desc')
        try:
            params_list.append(Parameter(
                param_desc, i, param_mode, param_size, param_doc
            ))
        except ValueError as e:
            message = (
                '{}:{}: Cannot create wrapper for function '
                '{}: KeyError "{}"'
            ).format(abs_path, line_no, func_name, e)
            raise ValueError(message) from e

    params_dict: dict[str, Parameter] = {param.name: param for param in params_list}
    for param in params_list:
        if not isinstance(param.size, str):
            continue  # only looping over parameters that have a variable size
        try:
            if params_dict[param.size].is_in():
                params_dict[param.size].mode = 'size'
                params_dict[param.size].targets.append(param.name)
        except KeyError as e:
            message = (
                '{}:{}: {} is not a parameter of {}'
            ).format(abs_path, line_no, param.size, func_name)
            raise ValueError(message) from e

    return func_name, params_list, line_no


def create_dot_C_wrapper(func_name: str, params_list: list[Parameter]) -> str:
    """
    Uses a function as parsed by robotpy-cppheaderparser together with its
    doxygen comment in order to create an R wrapper

    Example: the function defined as follows
    ::
        /**
         * @brief description
         * @param[in] param1
         * @param[in,out] param2 array of length param1
         * @param[out] param3 array of length param1
         */
        int some_func(const int param1, int *param2, float *param3);

    Will produce a wrapper like this
    ::
        some.func <- function(param2){
          param1 <- min(length(param2))
          param2 <- as.integer(param2)
          param3 <- vector(mode="double", length=param1)
          AUTO_RET_PARAMS <- .C("some_func", param1, param2, param3)
          param2 <- AUTO_RET_PARAMS$param2
          param3 <- AUTO_RET_PARAMS$param3
          AUTO_RETVAL <- list("param2" = param2, "param3" = param3)
          return(AUTO_RETVAL)
        }

    Node that param2's mode is "double", as R doesn't support single precision

    :param func_name: The name of the C function
    :type func_name: str
    :param params_list: List of Parameter objects retrieved from parse_function_info
    :return: The R wrapper for the provided C function
    :rtype: str
    :raise: :py:class:`ValueError` when the function can't be parsed
    """
    wrapper_name = func_name.replace('_', '.')
    signature = [f'{wrapper_name} <- function(']
    center = ['){']
    ending = ['\treturn(AUTO_RETVAL)', '}']
    wrapper_params = []
    call_proper = f'\tAUTO_RET_PARAMS <- .C("{func_name}", '
    call_params = []
    before_call = []
    after_call = []

    size_parameters = list(filter(Parameter.is_size, params_list))

    for param in size_parameters:
        before_call.append(
            '\t{} <- min({})'
            .format(param,
                    ",".join([f"length({target})"
                              for target
                              in param.targets]))
        )

    for param in params_list:
        call_params.append(param.name)
        if 'in' in param.mode:
            wrapper_params.append('\t' + param.name)
            before_call.append(param.conversion)
            if isinstance(param.size, int):
                before_call.append(
                    f'\tstopifnot(length({param.name}) >= {param.size})'
                )
        if param.is_out():
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
                     + [',\n'.join(wrapper_params)]
                     + center
                     + before_call
                     + [call_proper]
                     + after_call
                     + ending)


def create_wrappers_for_header_file(path: str,
                                    out_dir: str,
                                    namespace: Collection[str] = None):
    Path(out_dir).mkdir(parents=True, exist_ok=True)
    r_out_path = Path(out_dir, Path(path).name.replace('.h', '.R'))
    c_out_path = Path(out_dir, Path(path).name.replace('.h', '_wrappers.c'))
    r_wrappers = []
    c_wrappers = []
    for func in extract_functions_from_file(path):
        absolute_path = Path(path).absolute()
        name, params, _ = parse_function_info(func, absolute_path)
        if namespace is None or name in namespace:
            try:
                if sum(map(Parameter.is_out, params)) > 0:  # create a .C wrapper if there are output parameters
                    r_wrapper = create_dot_C_wrapper(name, params)
                    c_wrapper = ''
                else:  # create a .Call/.External wrapper
                    warnings.warn('Generating .Call wrappers is not yet fully supported')
                    r_wrapper = c_wrapper = ''
                r_wrappers.append(r_wrapper)
                c_wrappers.append(c_wrapper)
            except Exception as e:
                print(e, file=stderr)

    if any(r_wrappers):  # only create the file if there's anything to write
        try:
            # we force utf-8 encoding to avoid any strange encodings windows tends to use on some locales
            with open(r_out_path, 'w', encoding='utf-8') as fout:
                print('\n\n\n'.join(filter(None, r_wrappers)), file=fout)
        except IOError as e:
            print(e, file=stderr)

    if any(c_wrappers):
        try:
            with open(c_out_path, 'w', encoding='utf-8') as fout:
                print('#include <Rinternals.h>', end='\n\n\n', file=fout)
                print('\n\n\n'.join(filter(None, c_wrappers)), file=fout)
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
        print("Couldn't retrieve namespace file \"{}\", assuming all functions"
              .format(Path(path).absolute()), file=stderr)
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
