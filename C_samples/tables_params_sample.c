#include <stdio.h>
#include <stdbool.h>

#include "multiple_in_out_params_sample.h"
#include <math.h>

/* -------------------- Auxilliary functions ------------------------*/

static float table_sum(float* table, unsigned int length)
{
    float sum = 0;
    for (unsigned int i=0; i<length; i++)
    {
        sum += table[i];
    }

    return sum;
}

/* -------------------- One table in, one table out params ------------------------*/

void one_table_in_one_table_out_params_no_return_function( char* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param__out_one)
{
    return;
}

int one_table_in_one_table_out_params_int_return_function( char* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param__out_one)
{
    return 0;
}

unsigned int one_table_in_one_table_out_params_unsigned_int_return_function( char* table_param_in_one,
                                                                                unsigned int size_param_in_one,
                                                                                double* table_param_out_one,
                                                                                unsigned int size_param__out_one)
{
    return 0;
}


float one_table_in_one_table_out_params_float_return_function( char* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                double* table_param_out_one,
                                                                unsigned int size_param__out_one)
{
    return 0;
}

double one_table_in_one_table_out_params_double_return_function( char* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    double* table_param_out_one,
                                                                    unsigned int size_param__out_one)
{
    return 0;
}

bool one_table_in_one_table_out_params_bool_return_function( char* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                double* table_param_out_one,
                                                                unsigned int size_param__out_one)
{
    return 0;
}



