#ifndef __NO_PARAMS__
#define __NO_PARAMS__

#include <stdbool.h>

/**
 * Prints new line characters on console.
 * 
 */
void no_params_no_return_function(void);

/**
 * This functions always returns -1
 *
 * @return status code
 */
int no_params_int_return_function(void);

/**
 * This functions always returns 10
 *
 * @return status code
 */
unsigned int no_params_unsigned_int_return_function(void);

/**
 * This functions always returns 1.2
 *
 * @return dummy number
 */
float no_params_float_return_function(void);

/**
 * This functions always returns 0.5
 *
 * @return dummy number
 */
double no_params_double_return_function(void);

/**
 * This functions always returns true
 *
 * @return status code
 */
bool no_params_bool_return_function(void);

#endif
