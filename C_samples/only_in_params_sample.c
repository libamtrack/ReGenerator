#include <stdio.h>
#include <stdbool.h>

#include "only_in_params_sample.h"

void one_in_param_no_return_function(int param_one)
{
    printf("\r\n");
}


int one_in_param_int_return_function(int param_one)
{
    return -1;
}


unsigned int one_in_param_unsigned_int_return_function(int param_one)
{
    return 10;
}


float one_in_param_float_return_function(int param_one)
{
    return 1.2;
}


double one_in_param_double_return_function(int param_one)
{
    return 0.5;
}


bool one_in_param_bool_return_function(int param_one)
{
    return true;
}