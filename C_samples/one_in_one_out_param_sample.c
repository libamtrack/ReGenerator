#include <stdio.h>
#include <stdbool.h>

#include "one_in_one_out_param_sample.h"

void one_in_one_out_param_no_return_function(int param_one, double* param_out)
{
    printf("\r\n");
}


int one_in_one_out_param_int_return_function(int param_one, double* param_out)
{
    return -1;
}


unsigned int one_in_one_out_param_unsigned_int_return_function(int param_one, double* param_out)
{
    return 10;
}


float one_in_one_out_param_float_return_function(int param_one, double* param_out)
{
    return 1.2;
}


double one_in_one_out_param_double_return_function(int param_one, double* param_out)
{
    return 0.5;
}


bool one_in_one_out_param_bool_return_function(int param_one, double* param_out)
{
    return true;
}
