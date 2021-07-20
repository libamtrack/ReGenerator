#ifndef __IN_OUT_PARAMS__
#define __IN_OUT_PARAMS__

/**
 * Prints new line characters on console.
 * 
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 */
void one_in_one_out_param_no_return_function(int param_in, double* param_out);

/**
 * This functions always returns -1
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return status code
 */
int one_in_one_out_param_int_return_function(int param_in, double* param_out);

/**
 * This functions always returns 10
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return status code
 */
unsigned int one_in_one_out_param_unsigned_int_return_function(int param_in, double* param_out);

/**
 * This functions always returns 1.2
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return dummy number
 */
float one_in_one_out_param_float_return_function(int param_in, double* param_out);

/**
 * This functions always returns 0.5
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return dummy number
 */
double one_in_one_out_param_double_return_function(int param_in, double* param_out);

/**
 * This functions always returns true
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return status code
 */
bool one_in_one_out_param_bool_return_function(int param_in, double* param_out);


#endif
