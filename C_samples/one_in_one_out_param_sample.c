#include <stdio.h>
#include <stdbool.h>

#include "one_in_one_out_param_sample.h"

void one_in_one_out_param_no_return_function(int param_one, double* param_out)
{
    printf("\r\n");
}


int one_in_one_out_param_int_return_function(int param_one, double* param_out)
{
    *param_out = 1.5 * param_one;
    return -1 * param_one;
}


unsigned int one_in_one_out_param_unsigned_int_return_function(int param_one, double* param_out)
{
    *param_out = 1.5 * param_one;
    return 10 * param_one;
}


float one_in_one_out_param_float_return_function(int param_one, double* param_out)
{
    *param_out = 1.5 * param_one;
    return 1.2 * param_one;
}


double one_in_one_out_param_double_return_function(int param_one, double* param_out)
{
    *param_out = 1.5 * param_one;
    return 0.5 * param_one;
}


bool one_in_one_out_param_bool_return_function(int param_one, double* param_out)
{
    *param_out = 1.5 * param_one;
    return param_one > 10;
}
