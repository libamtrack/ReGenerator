#ifndef __ONLY_OUT_PARAMS__
#define __ONLY_OUT_PARAMS__

/**
 * Prints new line characters on console.
 * 
 * @param[out] param_one first param
 */
void one_out_param_no_return_function(int* param_one)

/**
 * This functions always returns -1
 *
 * @param[out] param_one first param
 *
 * @return status code
 */
int one_out_param_int_return_function(int* param_one)

/**
 * This functions always returns 10
 *
 * @param[out] param_one first param
 *
 * @return status code
 */
unsigned int one_out_param_unsigned_int_return_function(int* param_one)

/**
 * This functions always returns 1.2
 *
 * @param[out] param_one first param
 *
 * @return dummy number
 */
float one_out_param_float_return_function(int* param_one)

/**
 * This functions always returns 0.5
 *
 * @param[out] param_one first param
 *
 * @return dummy number
 */
double one_out_param_double_return_function(int* param_one)

/**
 * This functions always returns true
 *
 * @param[out] param_one first param
 *
 * @return status code
 */
bool one_out_param_bool_return_function(int* param_one)


#endif
