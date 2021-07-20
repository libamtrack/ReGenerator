#include <stdio.h>
#include <stdbool.h>

#include "no_params_sample.h"

void no_params_no_return_function(void)
{
    printf("\r\n");
}


int no_params_int_return_function(void)
{
    return -1;
}


unsigned int no_params_unsigned_int_return_function(void)
{
    return 10;
}


float no_params_float_return_function(void)
{
    return 1.2;
}


double no_params_double_return_function(void)
{
    return 0.5;
}


bool no_params_bool_return_function(void)
{
    return true;
}
