from ctypes import *
from collections import defaultdict


__all__ = ['mapping', 'type_registration', 'SEXP_conversion', 'str_to_ctype']


# mapping from C type to vector types ('modes') as they are seen in R
# used for type checking (is.TYPE), conversion (as.TYPE) and construction (TYPE)
mapping = defaultdict(lambda: 'error.type', {
    c_bool: 'logical',
    c_char: 'character',
    POINTER(c_char): 'character',
    c_char_p: 'character',
    c_ubyte: 'raw',
    c_int16: 'integer',
    c_int32: 'integer',
    c_int64: 'integer',
    c_uint16: 'integer',
    c_uint32: 'integer',
    c_uint64: 'integer',
    c_float: 'single',
    c_double: 'double',
    c_void_p: 'raw'
})


# SEXPTYPE as defined in R's C API, used mainly when constructing R objects
# from within C code
# comprehensive list of R types can be found here: https://cran.r-project.org/doc/manuals/r-release/R-ints.html
# in short:
# - NILSXP: NULL (not to be confused with NA, which can appear in multiple different types)
# - CHARSXP: internal character strings
# - LGLSXP: logical vectors
# - INTSXP: integer vectors
# - REALSXP: numeric vectors
# - RAWSXP: raw vector (i.e. a vector of unsigned bytes)
type_registration = defaultdict(lambda: 'NILSXP', {
    c_bool: 'LGLSXP',
    c_char: 'CHARSXP',
    POINTER(c_char): 'CHARSXP',
    c_char_p: 'CHARSXP',
    c_ubyte: 'RAWSXP',
    c_int16: 'INTSXP',
    c_int32: 'INTSXP',
    c_int64: 'INTSXP',
    c_uint16: 'INTSXP',
    c_uint32: 'INTSXP',
    c_uint64: 'INTSXP',
    c_float: 'REALSXP',
    c_double: 'REALSXP',
    c_void_p: 'RAWSXP'
})


# Conversion functions which extract C arrays from SEXP objects
# in short:
# - LOGICAL: logical -> int *
# - R_CHAR: character -> char *
# - RAW: raw -> unsigned char *
# - INTEGER: integer -> int *
# - REAL: numeric -> double *
SEXP_conversion = {
    c_bool: 'LOGICAL',
    c_char: 'R_CHAR',
    POINTER(c_char): 'R_CHAR',
    c_char_p: 'R_CHAR',
    c_ubyte: 'RAW',
    c_int16: 'INTEGER',
    c_int32: 'INTEGER',
    c_int64: 'INTEGER',
    c_uint16: 'INTEGER',
    c_uint32: 'INTEGER',
    c_uint64: 'INTEGER',
    c_float: 'REAL',
    c_double: 'REAL',
    c_void_p: 'RAW'
}


# simple conversion table from a c declaration to a ctypes class
declarations_conversion = {
    'char': c_char,
    'short': c_short,
    'int': c_int,
    'long': c_long,
    'long long': c_longlong,
    'unsigned char': c_ubyte,
    'unsigned short': c_ushort,
    'unsigned int': c_uint,
    'unsigned long': c_ulong,
    'unsigned long long': c_ulonglong,

    'float': c_float,
    'double': c_double,
    'long double': c_longdouble,

    'int8_t': c_int8,
    'int16_t': c_int16,
    'int32_t': c_int32,
    'int64_t': c_int64,
    'uint8_t': c_uint8,
    'uint16_t': c_uint16,
    'uint32_t': c_uint32,
    'uint64_t': c_uint64,

    'void*': c_void_p
}


def str_to_ctype(type_: str):
    type_ = type_.strip()
    if type_ in declarations_conversion:
        return declarations_conversion[type_]
    elif '*' in type_:
        return POINTER(str_to_ctype(type_.replace('*', '', 1)))
    elif 'int' in type_ and type != 'int':  # 'int' is omitted where it's not mandatory
        return str_to_ctype(type_.replace('int', ''))
    else:
        return declarations_conversion[type_]  # will raise a KeyError that we'll want to catch later


# adding pointers because we also want to cover arrays
for ctype in list(mapping.keys()):
    mapping[POINTER(ctype)] = mapping[ctype]
    type_registration[POINTER(ctype)] = type_registration[ctype]
    SEXP_conversion[POINTER(ctype)] = SEXP_conversion[ctype]
