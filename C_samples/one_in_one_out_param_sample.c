#include <stdio.h>

#include "one_in_one_out_param_sample.h"

void one_in_one_out_param_no_return_function(int param_in, double* param_out)
{
    printf("%d, %f\r\n", param_in, *param_out);
    *param_out = 1.5 * param_in;
}


int one_in_one_out_param_int_return_function(int param_in, double* param_out)
{
    *param_out = 1.5 * param_in;
    return -1 * param_in;
}


unsigned int one_in_one_out_param_unsigned_int_return_function(int param_in, double* param_out)
{
    *param_out = 1.5 * param_in;
    return 10 * param_in;
}


float one_in_one_out_param_float_return_function(int param_in, double* param_out)
{
    *param_out = 1.5 * param_in;
    return 1.2 * param_in;
}


double one_in_one_out_param_double_return_function(int param_in, double* param_out)
{
    *param_out = 1.5 * param_in;
    return 0.5 * param_in;
}


bool one_in_one_out_param_bool_return_function(int param_in, double* param_out)
{
    *param_out = 1.5 * param_in;
    return param_in > 10;
}
