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
 * This functions returns param_in multiplied by -1. 
 * Param_out is set to param_in multiplied by 1.5.
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return status code
 */
int one_in_one_out_param_int_return_function(int param_in, double* param_out);

/**
 * This functions always param_in multiplied by 10. 
 * Param_out is set to param_in multiplied by 1.5.
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return status code
 */
unsigned int one_in_one_out_param_unsigned_int_return_function(int param_in, double* param_out);

/**
 * This functions returns param_in multiplied by 1.2. 
 * Param_out is set to param_in multiplied by 1.5.
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return dummy number
 */
float one_in_one_out_param_float_return_function(int param_in, double* param_out);

/**
 * This functions returns param_in multiplied by 0.5. 
 * Param_out is set to param_in multiplied by 1.5.
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return dummy number
 */
double one_in_one_out_param_double_return_function(int param_in, double* param_out);

/**
 * This functions checks if param_in is greater than 10. 
 * Param out is set to param_in multiplied by 1.5.
 *
 * @param[in] param_in first param
 * @param[out] param_out second param
 *
 * @return status code
 */
bool one_in_one_out_param_bool_return_function(int param_in, double* param_out);


#endif
