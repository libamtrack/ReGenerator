from ctypes import *
from collections import defaultdict


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
    c_double: 'double'
})


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
    c_double: 'REALSXP'
})


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
    c_double: 'REAL'
}


for ctype in list(mapping.keys()):
    mapping[POINTER(ctype)] = mapping[ctype]
    type_registration[POINTER(ctype)] = type_registration[ctype]
    SEXP_conversion[POINTER(ctype)] = SEXP_conversion[ctype]
