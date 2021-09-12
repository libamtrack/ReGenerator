#include <stdio.h>

#include "only_in_params_sample.h"

void one_in_param_no_return_function(int param_one)
{
    printf("%d\r\n", param_one);
}


int one_in_param_int_return_function(int param_one)
{
    return -1 * param_one;
}


unsigned int one_in_param_unsigned_int_return_function(int param_one)
{
    return 10 * param_one;
}


float one_in_param_float_return_function(int param_one)
{
    return 1.2 * param_one;
}


double one_in_param_double_return_function(int param_one)
{
    return 0.5 * param_one;
}


bool one_in_param_bool_return_function(int param_one)
{
    return param_one > 10;
}
