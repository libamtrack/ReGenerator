#ifndef __ONLY_IN_PARAMS__
#define __ONLY_IN_PARAMS__

#include <stdbool.h>

/**
 * Prints param_one value on console.
 * 
 * @param[in] param_one first param
 */
void one_in_param_no_return_function(int param_one);

/**
 * This functions returns param_one value multiplied by -1
 *
 * @param[in] param_one first param
 *
 * @return param_one value multiplied by -1
 */
int one_in_param_int_return_function(int param_one);

/**
 * This functions returns param_one value multiplied by 10
 *
 * @param[in] param_one first param
 *
 * @return param_one value multiplied by 10
 */
unsigned int one_in_param_unsigned_int_return_function(int param_one);

/**
 * This functions returns param_one value multiplied by 1.2
 *
 * @param[in] param_one first param
 *
 * @return param_one value multiplied by 1.2
 */
float one_in_param_float_return_function(int param_one);

/**
 * This functions returns param_one value multiplied by 0.5
 *
 * @param[in] param_one first param
 *
 * @return param_one value multiplied by 0.5
 */
double one_in_param_double_return_function(int param_one);

/**
 * This functions checks if param_one is greater that 10.
 *
 * @param[in] param_one first param
 *
 * @return boolean value telling if param_one is greater that 10.
 */
bool one_in_param_bool_return_function(int param_one);


#endif
