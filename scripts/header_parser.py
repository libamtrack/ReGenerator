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
'    result of the function'

>>> m = param_regex.fullmatch('\\param[in,out] temp__    temperature '
... 'measurements before and afer (array of length 14)')
>>> m is None
False
>>> m.group('mode')
'[in,out]'
>>> m.group('name')
'temp__'
>>> m.group('desc')
'    temperature measurements before and afer (array of length 14)'

>>> m = param_regex.fullmatch('@param names    names of searched people (array of size number_of_people)')
>>> m is None
False
>>> m.group('mode')
''
>>> m.group('name')
'names'
>>> m.group('desc')
'    names of searched people (array of size number_of_people)'

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
from os import PathLike
from os.path import commonpath
from sys import stderr
from pathlib import Path, PurePosixPath
from collections.abc import Collection
from typing import Union, Literal

from CppHeaderParser import CppHeader, CppMethod, CppVariable

from ctype_translator import *

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


type_qualifiers = re.compile(r'volatile|const|restrict|register')


def extract_functions_from_file(path) -> list[CppMethod]:
    try:
        return CppHeader(path).functions
    except IOError:
        raise
    except (TypeError, ValueError, AttributeError) as e:
        message = f'{path} is not a valid C/C++ header file'
        raise ValueError(message) from e


class Parameter:
    """
    A parameter for a C function, as well as information about its doxygen
    comment and size (if array)
    """
    def __init__(self,
                 desc: CppVariable,
                 ordinal: int,
                 mode: str,
                 size: str = None,
                 description: str = ""):
        self.ord = ordinal
        self.ctype = eval(desc['ctypes_type'])
        self.raw_type: str = desc['raw_type'] + '*'*(desc['array'] + desc['pointer'])
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
        return f'\t{self.name} <- as.{self.Rtype}({self.name})'

    @property
    def Rtype(self):
        return mapping[self.ctype]

    @property
    def SEXP_conversion(self):
        return SEXP_conversion[self.ctype]


def parse_function_info(fun: CppMethod, abs_path: Path = None) -> tuple[str, list[Parameter]]:
    """
    Extracts the name and parameters from a given :class:`CppMethod` object

    :param fun: A CppMethod extracted by robotpy-cppheaderparser
    :param abs_path: absolute path to the header file
    :return: tuple containing the function's name and list of its parameters
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

    return func_name, params_list


def generate_external_call(func_name: str,
                           params_list: list[Parameter],
                           method: Literal['.C', '.Call'],
                           library_name: str = None) -> str:
    """
    Creates a call to .C or .Call with appropriate name and parameters.
    If library_name is omitted, creates a wrapper that looks everywhere for the function name.
    If method is .Call, it will call the C wrapper to func_name.

    :param func_name: name of the function
    :param params_list: list of the function's parameters
    :param method: whether to create a .C or a .Call wrapper
    :param library_name: where the call should look for the function
    :return: full call to .C/.Call
    """
    if method == '.Call':
        func_name += '_wrapper'
    ret = [method, '("', func_name, '"']
    if len(params_list) > 0:
        ret.append(', ' + ', '.join(param.name for param in params_list))
    if library_name is not None:
        ret.append(f'PACKAGE = "{library_name}"')
    ret.append(')')
    return ''.join(ret)


def generate_dot_C_wrapper(func_name: str,
                           params_list: list[Parameter],
                           export=False) -> str:
    """
    Uses a function name and parameters list returned by :func:`parse_function_info`
    to create an R wrapper with its .C function

    Example: the function defined as follows::

        /**
         * calculates time step for balancing pressure in pipes
         * @\0param         n         number of segments
         * @\0param         dt        time step size
         * @\0param[in]     widths    widths of pipe segments (array of length n)
         * @\0param[in,out] pressures array of length n, pressures before and after
         * @\0param[out]    dp        pressure changes (array of size n)
         */
        int pressure_step(
            const int n, const float dt,
            const float *widths,
            float *pressures, float *dp);

    Will produce a wrapper like this::

        pressure.step <- function(
            dt,
            widths,
            pressures
        ){
            n <- min(length(widths), length(pressures), length(dp))
            dt <- as.single(dt)
            widths <- as.single(widths)
            stopifnot(length(widths) >= n)
            pressures <- as.single(pressures)
            stopifnot(length(pressures) >= n)
            dp <- single(n)
            AUTO_RET_PARAMS <- .C("pressure_step", n, dt, widths, pressures, dp)
            pressures <- AUTO_RET_PARAMS$pressures
            dp <- AUTO_RET_PARAMS$dp
            AUTO_RETVAL <- list("pressures" = pressures, "dp" = dp)
            return(AUTO_RETVAL)
        }

    :param str func_name: The name of the C function
    :param params_list: List of Parameter objects retrieved from parse_function_info
    :param bool export: Whether the wrapper should be included in package namespace
    :return: The R wrapper for the provided C function
    :rtype: str
    """
    docstring = ['#` @export'] if export else []
    wrapper_name = func_name.replace('_', '.')
    signature = [f'{wrapper_name} <- function(']
    center = ['){']
    ending = ['\treturn(AUTO_RETVAL)', '}']
    wrapper_params = []
    call_proper = [f'''\tAUTO_RET_PARAMS <- {generate_external_call(
        func_name, params_list, '.C'
    )}''']
    before_call = []
    after_call = []

    size_parameters = list(filter(Parameter.is_size, params_list))
    out_params = list(filter(Parameter.is_out, params_list))

    for param in size_parameters:
        before_call.append(
            '\t{} <- min({})'
            .format(param.name,
                    ", ".join([f"length({target})"
                              for target
                              in param.targets]))
        )

    for param in params_list:
        if 'in' in param.mode:
            wrapper_params.append('\t' + param.name)
            before_call.append(param.conversion)
            if param.size is not None:
                before_call.append(
                    f'\tstopifnot(length({param.name}) >= {param.size})'
                )
        if param.is_out():
            if param.mode == 'out':
                before_call.append(
                    f'\t{param.name} <- {param.Rtype}('
                    f'{param.size if param.size else 1})'
                )
            after_call.append(
                f'\t{param.name} <- AUTO_RET_PARAMS${param.name}'
            )

    if len(out_params) == 1:
        after_call.append(f'\tAUTO_RETVAL <- {out_params[0].name}')
    else:
        after_call.append(
            '\tAUTO_RETVAL <- list({})'
            .format(", ".join([f'"{p.name}" = {p.name}' for p in out_params]))
        )

    return '\n'.join(
        docstring
        + signature
        + [',\n'.join(wrapper_params)]
        + center
        + before_call
        + call_proper
        + after_call
        + ending
    )


def generate_dot_Call_wrapper(func_name: str,
                              params_list: list[Parameter],
                              export=False) -> str:
    """
    Uses a function name and parameters list returned by :func:`parse_function_info`
    to create an R wrapper with its .Call function

    Example: the function defined as follows::

        /**
         * calculates time step for balancing pressure in pipes
         * @\0param n  number of items
         * @\0param xs numbers to take mean of (array of length n)
         * @\0return harmonic mean of xs
         */
        double harmonic_mean(const int n, const double *xs);

    Will produce a wrapper like this::

        harmonic.mean <- function(
            xs
        ){
            xs <- as.double(xs)
            n <- min(length(xs))
            stopifnot(length(xs) >= n)
            return(.Call("harmonic_mean_wrapper", n, xs))
        }

    :param str func_name: The name of the C function
    :param params_list: List of Parameter objects retrieved from parse_function_info
    :param bool export: Whether the wrapper should be included in package namespace
    :return: The R wrapper for the provided C function
    :rtype: str
    """
    docstring = ['#` @export'] if export else []
    wrapper_name = func_name.replace('_', '.')
    signature = [f'{wrapper_name} <- function(']
    wrapper_params = []
    center = ['){']
    call_proper = [
        f'\treturn({generate_external_call(func_name, params_list, ".Call")})',
        '}'
    ]
    size_derivations = []
    size_checks = []
    type_conversions = []
    sized_parameters = set(filter(Parameter.is_array, params_list))
    lengths = set(filter(Parameter.is_size, params_list))
    for param in params_list:
        if param not in lengths:
            wrapper_params.append('\t' + param.name)
            if param in sized_parameters:
                size_checks.append(
                    f'\tstopifnot(length({param.name}) >= {param.size})'
                )
            type_conversions.append(param.conversion)
        else:
            size_derivations.append(
                '\t{} <- min({})'.format(
                    param.name,
                    ', '.join(f'length({t})' for t in param.targets)
                )
            )
    return '\n'.join(
        docstring
        + signature
        + wrapper_params
        + center
        + type_conversions
        + size_derivations
        + size_checks
        + call_proper
    )


def generate_C_wrapper(func_name: str,
                       params_list: list[Parameter],
                       return_type: str) -> str:
    """
    Uses a function name, its return type and its parameters (a list of
    :class:`Parameter`) to create a C wrapper to a C function using R's SEXP
    type.

    Example: the function defined as follows::

        /**
         * calculates time step for balancing pressure in pipes
         * @\0param n  number of items
         * @\0param xs numbers to take mean of (array of length n)
         * @\0return harmonic mean of xs
         */
        double harmonic_mean(const int n, const double *xs);

    Will produce a wrapper like this::

        SEXP harmonic_mean_wrapper(
            SEXP p_n,
            SEXP p_xs,
        ){
            SEXP RETVAL = PROTECT(AllocVector(REALSXP, 1));
            int n = *(INTEGER(p_n));
            double* xs = (double*)malloc(sizeof(double) * n);
            for(int i = 0; i < n; i++) xs[i] = (REAL(p_xs))[i];
            *(REAL(RETVAL)) = harmonic_mean(n, xs);
            free(xs);
            UNPROTECT(1);
            return RETVAL;
        }
    
    :param func_name: name of the base function
    :param params_list: list of :class:`Parameter`, parameters of ``func_name``
    :param return_type: return type of the base function, e.g. ``unsigned int``
    :return: a C wrapper compatible with the .Call interface
    """
    return_ctype = str_to_ctype(return_type)
    signature = [f'SEXP {func_name}_wrapper(']
    middle = [
        '){',
        '\tSEXP RETVAL = PROTECT(AllocVector({}, 1));'
        .format(type_registration[return_ctype])
    ]
    late = []
    call = ['\t*({}(RETVAL)) = {}({});'
            .format(SEXP_conversion[return_ctype],
                    func_name, ', '.join(f'{p.name}' for p in params_list))]
    end = ['\tUNPROTECT(1);', '\treturn RETVAL;', '}']
    for param in params_list:
        signature.append(f'\tSEXP p_{param.name},')
        if param.size is None:
            if (not param.raw_type.endswith('*')) or param.raw_type == 'char*':
                middle.append(
                    '\t{0} {1} = *({2}(p_{1}));'
                    .format(param.raw_type, param.name,
                            param.SEXP_conversion)
                )
            elif param.raw_type == 'char**':
                middle.append('\tchar** {} = (char**)malloc(sizeof(char*));'
                              .format(param.name))
                middle.append('\t*{0} = R_CHAR(p_{0});'.format(param.name))
                call.append(f'\tfree({param.name});')
            else:
                middle.append(
                    '\t{0} {1} = ({0})malloc(sizeof({2}));'
                    .format(param.raw_type, param.name,
                            param.raw_type.replace('*', '', 1))
                )
                middle.append(
                    '\t*{0} = *({1}(p_{0}));'
                    .format(param.name, param.SEXP_conversion)
                )
                call.append(f'\tfree({param.name});')
        else:
            middle.append(
                '\t{0} {1} = ({0})malloc(sizeof({2}) * {3});'
                .format(param.raw_type, param.name,
                        param.raw_type.replace('*', '', 1),
                        param.size)
            )
            if param.raw_type == 'char**':
                middle.append(
                    '\tfor(int i = 0; i < {2}; i++) {0}[i] = R_STRING((STRING_ELT(p_{0}))[i]);'
                    .format(param.name, param.SEXP_conversion,
                            param.size)
                )
            else:
                middle.append(
                    '\tfor(int i = 0; i < {2}; i++) {0}[i] = ({1}(p_{0}))[i];'
                    .format(param.name, param.SEXP_conversion,
                            param.size)
                )
            call.append(f'\tfree({param.name});')
    return '\n'.join(
        signature
        + middle
        + late
        + call
        + end
    )


def create_wrappers_for_header_file(path: Union[str, PathLike[str]],
                                    out_dir: str,
                                    include_dir: Union[str, PathLike[str]],
                                    namespace: Collection[str] = None,
                                    exp_namespace: Collection[str] = None):
    """
    Reads a given header file and creates R and (eventually) C wrappers
    for the functions defined inside.

    :param include_dir: root directory for all header files
    :param path: path to the C header file
    :param out_dir: where to create files with wrappers
    :param namespace: functions for which we want wrappers to be created
    :param exp_namespace: functions which we want to export in final package
    :return:
    """
    Path(out_dir).mkdir(parents=True, exist_ok=True)
    r_out_path = Path(out_dir, Path(path).name.replace('.h', '.R'))
    c_out_path = Path(out_dir, Path(path).name.replace('.h', '_wrappers.c'))
    r_wrappers = []
    c_wrappers = []
    ret = set()
    for func in extract_functions_from_file(path):
        func['rtnType'] = re.sub(type_qualifiers, '', func['rtnType'])
        # we're only interested in scalar values
        try:
            absolute_path = Path(path).absolute()
            name, params = parse_function_info(func, absolute_path)
            # in case NAMESPACE file is not provided (here `namespace is None`) we generate wrappers for all functions
            # otherwise wrappers are generated only for functions listed in NAMESPACE file (here `name in namespace`)
            if namespace is None or name in namespace:
                # likewise, if no NAMESPACE file is provided, we export all functions
                export = exp_namespace is None or name in exp_namespace
                if any(map(Parameter.is_out, params)):  # create a .C wrapper if there are output parameters
                    r_wrapper = generate_dot_C_wrapper(name, params, export)
                    c_wrapper = ''
                    ret.add(name)
                elif func['rtnType'] != 'void':  # create a .Call/.External wrapper
                    r_wrapper = generate_dot_Call_wrapper(name, params, export)
                    c_wrapper = generate_C_wrapper(name, params, func['rtnType'])
                    ret.add(name)
                else:  # void func with no in params - nothing to create a wrapper for
                    message = 'void function with no out parameter won\'t create a wrapper'
                    warnings.warn(message)
                    r_wrapper = c_wrapper = ''

                r_wrappers.append(r_wrapper)
                c_wrappers.append(c_wrapper)
        except Exception as e:
            message = f'{path}: {type(e)} while creating wrapper for {func}: {e}'
            print(message, file=stderr)

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
                print('#include <Rinternals.h>', file=fout)
                c_include_filename = PurePosixPath(path).relative_to(PurePosixPath(include_dir))
                print(f'#include "{c_include_filename}"', end='\n\n\n', file=fout)
                print('\n\n\n'.join(filter(None, c_wrappers)), file=fout)
        except IOError as e:
            print(e, file=stderr)
    return ret


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
            export.add(name)
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
    exp_wrapper, gen_wrapper = read_namespace(args.namespace)

    infiles = [Path(p).absolute() for p in args.infile]
    if len(infiles) > 1:
        include_dir = Path(commonpath(infiles))
    else:
        include_dir = infiles[0].parent

    for infile in infiles:
        create_wrappers_for_header_file(infile, args.out_dir, include_dir, gen_wrapper, exp_wrapper)


if __name__ == '__main__':
    main()
