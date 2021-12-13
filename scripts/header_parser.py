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
import logging
import re
import argparse
import ctypes  # used by eval
from glob import glob
from os import PathLike
from os.path import commonpath
from sys import stderr
from pathlib import Path, PurePosixPath, PurePath
from collections.abc import Collection
from typing import Union, Literal, TextIO

from CppHeaderParser import CppHeader, CppMethod, CppVariable

from ctype_translator import *
from expressions import Expression


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
array_regex = re.compile(r'array\s*of\s*(length|size)\s*(?P<lname>[a-z0-9_^*/+-]+)')


type_qualifiers = re.compile(r'volatile|const|restrict|register')


#  Any amount of whitespace, if followed by a '('
function_name_end = re.compile(r'\s*(?=\()')


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
        self.raw_type: str = (
            desc['raw_type'] +
            '*' * (desc['array'] + desc['pointer'])
        )
        self.name: str = desc['name']
        self.mode: str = mode[1:-1].lower() if mode != '' else 'in'
        self.size: Union[str, int, None, Expression] = Expression(size)
        self.targets = []  # only used with size parameters
        self.description = description.strip()

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

    @property
    def SEXPTYPE(self):
        return type_registration[self.ctype]


def extract_functions_from_file(path) -> list[CppMethod]:
    try:
        return CppHeader(path).functions
    except IOError:
        raise
    except (TypeError, ValueError, AttributeError) as e:
        message = f'{path} is not a valid C/C++ header file'
        raise ValueError(message) from e


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

    params_dict: dict[str, Parameter] = {
        param.name: param for param in params_list
    }
    for param in params_list:
        if not isinstance(param.size, str):
            continue  # only looping over parameters that have a variable size
        try:
            if params_dict[param.size].is_in() and param.is_in():
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

    If library_name is omitted, creates a wrapper that looks everywhere
    for the function name.

    If method is .Call, it will call the C wrapper to func_name.

    :param func_name: name of the function
    :param params_list: list of the function's parameters
    :param method: whether to create a .C or a .Call wrapper
    :param library_name: where the call should look for the function
    :return: full call to .C/.Call
    """
    ret = [method, '("', func_name, '_wrapper"']
    if len(params_list) > 0:
        ret.append(', ' + ', '.join(
            # in .C we want to name the parameters
            # so that we can later access them by name
            (param.name if method ==
             '.Call' else '{0} = {0}'.format(param.name))
            for param in params_list))
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
    docstring = ['#\' @export'] if export else []
    wrapper_name = func_name.replace('_', '.')
    signature = [f'{wrapper_name} <- function(']
    center = ['){']
    ending = ['\treturn(AUTO_RETVAL)', '}']
    wrapper_params = []
    call_proper = [f'''\tAUTO_RET_PARAMS <- {generate_external_call(
        func_name, params_list, '.C'
    )}''']
    before_call_latter = []
    before_call_former = []
    after_call = []

    out_params = list(filter(Parameter.is_out, params_list))
    size_parameters = list(filter(Parameter.is_size, params_list))

    logging.debug(f'Creating R function {wrapper_name} (.C)')

    for param in size_parameters:
        before_call_latter.append(
            '\t{} <- min({})'
            .format(param.name,
                    ", ".join([f"length({target})"
                              for target
                              in param.targets]))
        )

    for param in params_list:
        if 'in' in param.mode:
            wrapper_params.append('\t' + param.name)
            before_call_former.append(param.conversion)
            if param.size is not None:
                before_call_latter.append(
                    f'\tstopifnot(length({param.name}) >= '
                    f'{str(param.size).replace("/", "%/%")})'
                )
        if param.is_out():
            if param.mode == 'out':
                before_call_latter.append(
                    f'\t{param.name} <- {param.Rtype}('
                    f'{str(param.size).replace("/", "%/%") if param.size else 1})'
                )
            after_call.append(
                f'\t{param.name} <- AUTO_RET_PARAMS${param.name}'
            )

    if len(out_params) == 1:
        after_call.append(f'\tAUTO_RETVAL <- {out_params[0].name}')
    else:
        after_call.append(
            '\tAUTO_RETVAL <- list({})'
            .format(", ".join([f'{p.name} = {p.name}' for p in out_params]))
        )

    return '\n'.join(
        docstring
        + signature
        + [',\n'.join(wrapper_params)]
        + center
        + before_call_former
        + before_call_latter
        + call_proper
        + after_call
        + ending
    )


def generate_C_wrapper_dot_C(func_name: str,
                             params_list: list[Parameter]) -> str:
    """
    Uses a function name, its return type and its parameters (a list of
    :class:`Parameter`) to create a C wrapper to a C function using the limited
    set of pointer types thar R's ``.C`` function uses.

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

        void pressure_step_wrapper(
            int * p_n,
            float * p_dt,
            float * p_widths,
            float * p_pressures,
            float * p_dp
        ){
            int n = *p_n;
            float dt = *p_dt;
            float* widths = (float*)malloc(sizeof(float) * n);
            for(int i = 0; i < n; i++) widths[i] = p_widths[i];
            float* pressures = (float*)malloc(sizeof(float) * n);
            for(int i = 0; i < n; i++) pressures[i] = p_pressures[i];
            float* dp = (float*)malloc(sizeof(float) * n);
            for(int i = 0; i < n; i++) dp[i] = p_dp[i];
            pressure_step(n, dt, widths, pressures, dp);
            for(int i = 0; i < n; i++) p_pressures[i] = pressures[i];
            for(int i = 0; i < n; i++) p_dp[i] = dp[i];
            free(widths);
            free(pressures);
            free(dp);
        }

    :param func_name: name of the function
    :param params_list: list of :class:`Parameter`, parameters of ``func_name``
    :return:
    """
    signature = [f'void {func_name}_wrapper(']
    middle = ['){']
    before_call_former = []
    before_call_latter = []
    call_proper = ['\t{}({});'.format(
        func_name,
        ', '.join(p.name for p in params_list)
    )]
    after_call = []
    cleanup = []
    end = ['}']

    logging.debug(f'Creating C function {func_name}_wrapper (.C)')

    for param in params_list:
        signature.append(f'\t{dot_C_conversions[param.Rtype]} p_{param.name},')

        if param.is_array():  # array
            if param.raw_type == 'char*':
                before_call_latter.append(
                    '\tchar* {0} = (char*)malloc({1});'
                    .format(param.name, param.size)
                )
                before_call_latter.append(
                    '\tfor(int i = 0; i < {1}; i++) {0}[i] = (*p_{0})[i];'
                    .format(param.name, param.size)
                )
                if param.is_out():
                    after_call.append(
                        '\tfor(int i = 0; i < {1}; i++) (*p_{0})[i] = {0}[i];'
                        .format(param.name, param.size)
                    )
            else:
                before_call_latter.append(
                    '\t{0} {1} = ({0})malloc(sizeof({2}) * ({3}));'
                    .format(param.raw_type, param.name,
                            param.raw_type.replace('*', '', 1),
                            param.size)
                )
                before_call_latter.append(
                    '\tfor(int i = 0; i < {1}; i++) {0}[i] = p_{0}[i];'
                    .format(param.name, param.size)
                )
                if param.is_out():
                    after_call.append(
                        '\tfor(int i = 0; i < {1}; i++) p_{0}[i] = {0}[i];'
                        .format(param.name, param.size)
                    )
            cleanup.append(
                f'\tfree({param.name});'
            )

        elif '*' in param.raw_type and param.raw_type != 'char*':  # scalar, as a pointer
            before_call_former.append(
                '\t{0} {1} = ({0})malloc(sizeof({2}));'
                .format(param.raw_type, param.name,
                        param.raw_type.replace('*', '', 1))
            )
            before_call_former.append(
                '\t*{0} = *p_{0};'.format(param.name)
            )
            if param.is_out():
                after_call.append(
                    '\t*p_{0} = *{0};'.format(param.name)
                )
            cleanup.append(
                f'\tfree({param.name});'
            )

        elif param.raw_type == 'char':  # special case because we receive a pointer to pointer to char
            before_call_former.append(
                '\tchar {0} = **p_{0};'
                .format(param.name)
            )

        else:  # scalar, as a value
            before_call_former.append(
                '\t{0} {1} = *p_{1};'
                .format(param.raw_type, param.name)
            )
            if param.is_out():  # for when we have a writeable char* parameter
                after_call.append(
                    '\t*p_{0} = {0};'.format(param.name)
                )

    # we need to trim the ',' after the last argument
    signature[-1] = signature[-1][:-1]
    return '\n'.join(
        signature
        + middle
        + before_call_former
        + before_call_latter
        + call_proper
        + after_call
        + cleanup
        + end
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
    docstring = ['#\' @export'] if export else []
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

    logging.debug(f'Creating R function {wrapper_name} (.Call)')

    for param in params_list:
        if param not in lengths:
            wrapper_params.append('\t' + param.name)
            if param in sized_parameters:
                size_checks.append(
                    f'\tstopifnot(length({param.name}) >= '
                    f'{str(param.size).replace("/", "%/%")})'
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
        + [',\n'.join(wrapper_params)]
        + center
        + type_conversions
        + size_derivations
        + size_checks
        + call_proper
    )


def generate_C_wrapper_dot_Call(func_name: str,
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

        /* includes omitted */
        SEXP harmonic_mean_wrapper(
            SEXP p_n,
            SEXP p_xs,
        ){
            SEXP RETVAL = PROTECT(allocVector(REALSXP % MAX_NUM_SEXPTYPE, 1));
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
    signature = [f'SEXP {func_name}_wrapper( ']
    middle = [
        '){',
        '\tSEXP RETVAL = PROTECT(allocVector({} % MAX_NUM_SEXPTYPE, 1));'
        .format(type_registration[return_ctype])
    ]
    late = []
    call = ['\t*({}(RETVAL)) = {}({});'
            .format(SEXP_conversion[return_ctype],
                    func_name, ', '.join(f'{p.name}' for p in params_list))]
    end = ['\tUNPROTECT(1);', '\treturn RETVAL;', '}']

    logging.debug(f'Creating C function {func_name}_wrapper (.Call)')

    for param in params_list:
        signature.append(f'\tSEXP p_{param.name},')
        if param.is_array():
            late.append(
                '\t{0} {1} = ({0})malloc(sizeof({2}) * ({3}));'
                .format(param.raw_type, param.name,
                        param.raw_type.replace('*', '', 1),
                        param.size)
            )
            if param.raw_type == 'char**':
                late.append(
                    '\tfor(int i = 0; i < {2}; i++) {0}[i] = R_STRING((STRING_ELT(p_{0}))[i]);'
                    .format(param.name, param.SEXP_conversion,
                            param.size)
                )
            else:
                late.append(
                    '\tfor(int i = 0; i < {2}; i++) {0}[i] = ({1}(p_{0}))[i];'
                    .format(param.name, param.SEXP_conversion,
                            param.size)
                )
            call.append(f'\tfree({param.name});')
        else:
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
    # we need to trim the ',' after the last argument
    signature[-1] = signature[-1][:-1]
    return '\n'.join(
        signature
        + middle
        + late
        + call
        + end
    )


# regular expressions used to extract information about function from doxygen
# get rid of doxygen-typical notation for comments
discarded_characters_pattern = re.compile(
    r'(/\*\*)|(\*/)|(^\s*\*\s*)|(///)',
    re.MULTILINE
)
# extract the `@return` command
return_pattern = re.compile(r'[@\\]return.*$', re.DOTALL)
# remove everything after the first parameter definition
params_pattern = re.compile(r'[@\\]param.*$', re.DOTALL)


def extract_doxygen(func: CppMethod, params: list[Parameter]):
    arguments = []
    raw = discarded_characters_pattern.sub('', func['doxygen'])

    if any(p.is_out() for p in params):
        returns = ["#' @return", "#' \\itemize{", "#' }"]
    else:
        returns = [
            "#' " + s for s
            in return_pattern.search(raw).group(0).split('\n')
        ]

    raw = params_pattern.sub('', raw).split('\n')
    description = ["#' " + s for s in raw]

    for param in params:
        if param.is_out():
            returns.insert(
                -1,
                f"#'    \\item {param.name}: {param.description}"
            )
        else:
            arguments.append(f"#' @param {param.name} {param.description}")

    return '\n'.join(
        description
        + arguments
        + returns
    )


def create_wrappers_for_header_file(path: Union[str, PathLike[str]],
                                    out_dir: str,
                                    include_dir: Union[str, PathLike[str]],
                                    init_file: TextIO,
                                    namespace: Collection[str] = None,
                                    exp_namespace: Collection[str] = None):
    """
    Reads a given header file and creates R and C (if necessary) wrappers
    for the functions defined inside.

    :param include_dir: root directory for all header files
    :param path: path to the C header file
    :param out_dir: where to create files with wrappers
    :param init_file: path to ``init.c``, which is where symbol registration
        for R interaction typically resides
    :param namespace: functions for which we want wrappers to be created
    :param exp_namespace: functions which we want to export in final package
    :return: information about symbols that need to be registered
    """
    Path(out_dir, 'R').mkdir(parents=True, exist_ok=True)
    r_out_path = Path(out_dir, 'R', Path(path).name.replace('.h', '.R'))
    c_out_path = Path(out_dir, 'src',
                      Path(path).name.replace('.h', '_wrappers.c'))
    r_wrappers = []
    c_wrappers = []
    dot_c_functions = []
    dot_call_functions = []

    ret = set()
    for func in extract_functions_from_file(path):
        func['rtnType'] = type_qualifiers.sub('', func['rtnType'])
        # we're only interested in scalar values
        try:
            absolute_path = Path(path).absolute()
            name, params = parse_function_info(func, absolute_path)
            # in case NAMESPACE file is not provided (here `namespace is None`) we generate wrappers for all functions
            # otherwise wrappers are generated only for functions listed in NAMESPACE file (here `name in namespace`)
            if namespace is None or name in namespace:
                # likewise, if no NAMESPACE file is provided, we export all functions
                export = exp_namespace is None or name in exp_namespace
                # create a .C wrapper if there are output parameters
                if any(map(Parameter.is_out, params)):
                    r_wrapper = generate_dot_C_wrapper(name, params, export)
                    c_wrapper = generate_C_wrapper_dot_C(name, params)
                    ret.add(name)

                    print('extern void', name + '_wrapper', '(',
                          ', '.join(dot_C_conversions[p.Rtype]
                                    for p in params),
                          ');', file=init_file)
                    dot_c_functions.append((name + '_wrapper', params))
                elif func['rtnType'] != 'void':  # create a .Call/.External wrapper
                    r_wrapper = generate_dot_Call_wrapper(name, params, export)
                    c_wrapper = generate_C_wrapper_dot_Call(
                        name, params, func['rtnType']
                    )
                    ret.add(name)
                    print(
                        'extern SEXP', name + '_wrapper', '(',
                        ', '.join(['SEXP'] * len(params)), ');',
                        file=init_file
                    )
                    dot_call_functions.append((name + '_wrapper', len(params)))
                else:  # void func with no in params - nothing to create a wrapper for
                    message = (
                        '{}:{}: void function `{}` with no out '
                        'parameter won\'t create a wrapper'
                        .format(Path(path).relative_to(include_dir),
                                func['line_number'], func['name'])
                    )
                    logging.info(message)
                    r_wrapper = c_wrapper = ''
                if r_wrapper:
                    r_wrapper = (extract_doxygen(func, params)
                                 + '\n' + r_wrapper)
                r_wrappers.append(r_wrapper)
                c_wrappers.append(c_wrapper)
        except Exception as e:
            message = f'{path}: {type(e)} while creating wrapper for {func["name"]}: {e}'
            logging.error(message)

    if any(r_wrappers):  # only create the file if there's anything to write
        try:
            # we force utf-8 encoding to avoid any strange encodings windows tends to use on some locales
            with open(r_out_path, 'w', encoding='utf-8') as fout:
                print('\n\n\n'.join(filter(None, r_wrappers)), file=fout)
        except IOError as e:
            message = f'Can\'t write R wrappers to {r_out_path}: {e}'
            logging.critical(message)

    if any(c_wrappers):
        try:
            with open(c_out_path, 'w', encoding='utf-8') as fout:
                write_cpp_directives(fout)
                c_include_filename = (
                    PurePosixPath(path)
                    .relative_to(PurePosixPath(include_dir))
                )
                print(f'#include "{c_include_filename}"',
                      end='\n\n\n', file=fout)
                print('\n\n\n'.join(filter(None, c_wrappers)), file=fout)
        except IOError as e:
            message = f'Can\'t write C wrappers to {c_out_path}: {e}'
            logging.critical(message)

    return dot_c_functions, dot_call_functions


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
        message = 'Couldn\'t retrieve namespace file "{}", assuming all functions'
        logging.warning(message.format(Path(path).absolute()))
        return None, None
    names = map(lambda x: re.sub(r'#.*$', '', x).strip(),
                names)  # remove comments
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


def register_symbols(project_base: TextIO,
                     dot_Call_funs: list[tuple[str, int]],
                     dot_C_funcs: list[tuple[str, list[Parameter]]]) -> None:
    """
    Writes C code responsible for registering symbols in R when loading
    the library file, allowing for fast lookup of relevant functions

    :param project_base: init.c file stream
    :param dot_Call_funs: names and numbers of parameters
        of functions used in .Call calls
    :param dot_C_funcs: names and parameters of functions used in .C calls
    """

    # wrappers used in .C calls
    dot_C_registrations = []
    for name, args in dot_C_funcs:
        print('R_NativePrimitiveArgType  ', name, '_args[] = {',
              ', '.join(arg.SEXPTYPE for arg in args),
              '};', sep='', file=project_base)
        dot_C_registrations.append(f'\tC_DECL({name}, {len(args)}),')

    print('\nR_CMethodDef cMethods[] = {', file=project_base)
    print('\n'.join(dot_C_registrations), file=project_base)
    print('\t{NULL, NULL, 0, NULL}', '};',
          sep='\n', end='\n\n', file=project_base)

    # wrappers used in .Call calls
    print('R_CallMethodDef callMethods[] = {', file=project_base)
    for name, n in dot_Call_funs:
        print(f'\tCALL_DECL({name}, {n}),', file=project_base)
    print('\t{NULL, NULL, 0}', file=project_base)
    print('};', file=project_base, end='\n\n')
    print('void R_init_lib(DllInfo *info){R_registerRoutines'
          '(info, cMethods, callMethods, NULL, NULL);}', file=project_base)


def write_cpp_directives(out: TextIO, declarations: bool = False) -> None:
    """
    Write necessary C preprocessor directives to out.

    :param out: C source file stream
    :param declarations: whether to include ``#define``s for CALL_DECL and C_DECL
    """
    print('#include<stdlib.h>', file=out)
    print('#include<stdbool.h>', file=out)
    print('#include<stdint.h>', file=out)
    print('#include<Rinternals.h>', file=out)
    print('#include<R_ext/Rdynload.h>', file=out, end='\n\n')
    if declarations:
        print('#define CALL_DECL(name, n) '
              '{#name, (DL_FUNC) &name, n}',
              file=out)
        print('#define C_DECL(name, n) {#name, '
              '(DL_FUNC) &name, n, name ## _args}',
              file=out, end='\n\n')


def main():
    parser = argparse.ArgumentParser(
        description='Create wrappers necessary to create an R package'
                    ' for functions declared in a header file(s)',
        epilog='''Glob patterns supported by this script are: 
    ? - matches any single character
    * - matches any string
    ** - matches any path recursively

For example, `?oo.txt` can match foo.txt and boo.txt, `*oo.txt` will \
additionally match kazoo.txt, and **oo.txt will match all of the above, as \
well as a/oo.txt and a/b/zoo.txt''',
        formatter_class=argparse.RawDescriptionHelpFormatter
    )
    parser.add_argument('infile', nargs='+',
                        help='C header files (or glob patterns) to be parsed')
    parser.add_argument('-o', '--out-dir', dest='out_dir', metavar='output_dir',
                        help='directory to write wrappers to, (default ./out)',
                        default='./out')
    parser.add_argument('-n', '--namespace', dest='namespace', metavar='namespace',
                        help='path to project namespace file (default ./NAMESPACE)',
                        default='./NAMESPACE')
    parser.add_argument('-l', '--log-file', dest='log_file', metavar='logfile',
                        help='Redirect logging information to logfile instead of stderr',
                        default=None)
    parser.add_argument('-v', '--verbose', dest='verbose', action='count',
                        help='Log more information, can be stacked up to 2 times. '
                        'Concels out with -q', default=0)
    parser.add_argument('-q', '--quiet', dest='quiet', action='count',
                        help='Log less information, can be stacked up to 2 times. '
                        'Cancels out with -v', default=0)
    args = parser.parse_args()

    verbosity = min(5, max(0, 2+args.verbose-args.quiet))
    verbosity_levels = [logging.CRITICAL, logging.ERROR,
                        logging.WARNING, logging.INFO, logging.NOTSET]
    logger_settings = {'level': verbosity_levels[verbosity]}
    if args.log_file:
        logger_settings['file'] = args.log_file
    else:
        logger_settings['stream'] = stderr

    logging.basicConfig(**logger_settings)

    exp_wrapper, gen_wrapper = read_namespace(args.namespace)

    infiles = sum((glob(p, recursive=True) for p in args.infile), start=[])
    infiles = [Path(p).absolute() for p in infiles]
    if len(infiles) > 1:
        include_dir = Path(commonpath(infiles))
    else:
        include_dir = infiles[0].parent

    c_path = Path(args.out_dir, 'src')
    c_path.mkdir(exist_ok=True, parents=True)
    dot_C_funcs = []
    dot_Call_funcs = []

    try:
        with open(c_path / 'init.c', 'w') as project_base:
            write_cpp_directives(project_base, True)
            for infile in infiles:
                C, Call = create_wrappers_for_header_file(
                    infile, args.out_dir, include_dir, project_base,
                    gen_wrapper, exp_wrapper
                )
                dot_Call_funcs += Call
                dot_C_funcs += C

            register_symbols(project_base, dot_Call_funcs, dot_C_funcs)

    except IOError as e:
        logging.critical(f'Can\'t open {c_path / "init.c"}: {e}')


if __name__ == '__main__':
    main()
