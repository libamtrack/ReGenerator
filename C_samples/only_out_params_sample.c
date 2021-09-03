#include <stdio.h>
#include <stdbool.h>

#include "only_out_params_sample.h"

void one_out_param_no_return_function(int* param_one)
{
    *param_one = 10;
    printf("\r\n");
}


int one_out_param_int_return_function(int* param_one)
{
    *param_one = 10;
    return -1;
}


unsigned int one_out_param_unsigned_int_return_function(int* param_one)
{
    *param_one = 10;
    return 10;
}


float one_out_param_float_return_function(int* param_one)
{
    *param_one = 10;
    return 1.2;
}


double one_out_param_double_return_function(int* param_one)
{
    *param_one = 10;
    return 0.5;
}


bool one_out_param_bool_return_function(int* param_one)
{
    *param_one = 10;
    return true;
}