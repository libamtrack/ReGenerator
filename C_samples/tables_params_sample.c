#include <stdio.h>
#include <stdbool.h>

#include "multiple_in_out_params_sample.h"
#include <math.h>

/* -------------------- Auxilliary functions ------------------------*/

static double table_sum(double* table, unsigned int length)
{
    double sum = 0;
    for (unsigned int i=0; i<length; i++)
    {
        sum += table[i];
    }

    return sum;
}

/* -------------------- One table in, no out params ------------------------*/

void one_table_in_no_out_params_no_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one)
{
    return;
}

int one_table_in_no_out_params_int_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one)
{
    return (int)table_sum(table_param_in_one, size_param_in_one);
}

unsigned int one_table_in_no_out_params_unsigned_int_return_function( double* table_param_in_one,
                                                                        unsigned int size_param_in_one)
{
    return (unsigned int)abs(table_sum(table_param_in_one, size_param_in_one));
}


float one_table_in_no_out_params_float_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one)
{
    return (float)table_sum(table_param_in_one, size_param_in_one);
}

double one_table_in_no_out_params_double_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one)
{
    return table_sum(table_param_in_one, size_param_in_one);
}

bool one_table_in_no_out_params_bool_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one)
{
    return table_sum(table_param_in_one, size_param_in_one) < 100.0;
}


/* -------------------- No in params, one table out ------------------------*/

void no_in_one_table_out_params_no_return_function( double* table_param_out_one,
                                                    unsigned int size_param_out_one)
{
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = 10.0;
    }
    return;
}

int no_in_one_table_out_params_int_return_function( double* table_param_out_one,
                                                    unsigned int size_param_out_one)
{
    int sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = -10;
        sum += table_param_out_one[i];
    }
    return sum;
}

unsigned int no_in_one_table_out_params_unsigned_int_return_function( double* table_param_out_one,
                                                                        unsigned int size_param_out_one)
{
    unsigned int sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = 10;
        sum += table_param_out_one[i];
    }
    return sum;
}


float no_in_one_table_out_params_float_return_function( double* table_param_out_one,
                                                        unsigned int size_param_out_one)
{
    float sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = 10.2;
        sum += table_param_out_one[i];
    }
    return sum;
}

double no_in_one_table_out_params_double_return_function( double* table_param_out_one,
                                                            unsigned int size_param_out_one)
{
    double sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = 10.2;
        sum += table_param_out_one[i];
    }
    return sum;
}

bool no_in_one_table_out_params_bool_return_function( double* table_param_out_one,
                                                        unsigned int size_param_out_one)
{
    double sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = 10.2;
        sum += table_param_out_one[i];
    }
    return sum < 100.0;
}


/* -------------------- One table in, one param out ------------------------*/


void one_table_in_one_out_param_no_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one,
                                                    float* param_out_one)
{
    *param_out_one = table_sum(table_param_in_one, size_param_in_one);
}

int one_table_in_one_out_param_int_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one,
                                                    float* param_out_one)
{
    *param_out_one = table_sum(table_param_in_one, size_param_in_one);
    return (int)(*param_out_one);
}

unsigned int one_table_in_one_out_param_unsigned_int_return_function( double* table_param_in_one,
                                                                        unsigned int size_param_in_one,
                                                                        float* param_out_one)
{
    *param_out_one = table_sum(table_param_in_one, size_param_in_one);
    return (unsigned int)abs(*param_out_one);
}


float one_table_in_one_out_param_float_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one,
                                                        float* param_out_one)
{
    *param_out_one = table_sum(table_param_in_one, size_param_in_one);
    return *param_out_one;
}

double one_table_in_one_out_param_double_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            float* param_out_one)
{
    *param_out_one = table_sum(table_param_in_one, size_param_in_one);
    return *param_out_one;
}

bool one_table_in_one_out_param_bool_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one,
                                                        float* param_out_one)
{
    *param_out_one = table_sum(table_param_in_one, size_param_in_one);
    return *param_out_one < 100.0;
}

/* -------------------- One in param, one table out ------------------------*/

void one_param_in_one_table_out_no_return_function( double param_in_one,
                                                        double* table_param_out_one,
                                                        unsigned int size_param_out_one)
{
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = param_in_one;
    }
    return;
}

int one_param_in_one_table_out_params_int_return_function( double param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one)
{
    int sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = param_in_one;
        sum += (int)(-1*param_in_one);
    }
    return sum;
}

unsigned int one_param_in_one_table_out_unsigned_int_return_function( double param_in_one,
                                                                        double* table_param_out_one,
                                                                        unsigned int size_param_out_one)
{
    unsigned int sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = param_in_one;
        sum += (unsigned int)abs(param_in_one);
    }
    return sum;
}


float one_param_in_one_table_out_float_return_function( double param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one)
{
    float sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = param_in_one;
        sum += param_in_one;
    }
    return sum;
}

double one_param_in_one_table_out_double_return_function( double param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one)
{
    double sum = 0;
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = param_in_one;
        sum += param_in_one;
    }
    return sum;
}

bool one_param_in_one_table_out_bool_return_function( double param_in_one,
                                                        double* table_param_out_one,
                                                        unsigned int size_param_out_one)
{
    for (unsigned int i=0;i<size_param_out_one;i++)
    {
        table_param_out_one[i] = param_in_one;
    }
    return param_in_one < size_param_out_one;
}

/* -------------------- One table in, one table out params ------------------------*/

void one_table_in_one_table_out_params_no_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            int* table_param_out_one,
                                                            unsigned int size_param_out_one)
{
    for (unsigned int i=0;i<size_param_out_one && i < size_param_in_one;i++)
    {
        table_param_out_one[i] = (int)table_param_in_one[i];
    }
    return;
}

int one_table_in_one_table_out_params_int_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            int* table_param_out_one,
                                                            unsigned int size_param_out_one)
{
    int sum = 0;
    for (unsigned int i=0;i<size_param_out_one && i < size_param_in_one;i++)
    {
        table_param_out_one[i] = (int)table_param_in_one[i];
        sum += table_param_out_one[i];
    }
    return sum;
}

unsigned int one_table_in_one_table_out_params_unsigned_int_return_function( double* table_param_in_one,
                                                                                unsigned int size_param_in_one,
                                                                                int* table_param_out_one,
                                                                                unsigned int size_param_out_one)
{
    int sum = 0;
    for (unsigned int i=0;i<size_param_out_one && i < size_param_in_one;i++)
    {
        table_param_out_one[i] = (int)table_param_in_one[i];
        sum += table_param_out_one[i];
    }
    return abs(sum);
}


float one_table_in_one_table_out_params_float_return_function( double* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_out_one,
                                                                unsigned int size_param_out_one)
{
    float sum = 0;
    for (unsigned int i=0;i<size_param_out_one && i < size_param_in_one;i++)
    {
        table_param_out_one[i] = (int)table_param_in_one[i];
        sum += table_param_in_one[i];
    }
    return sum;
}

double one_table_in_one_table_out_params_double_return_function( double* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    int* table_param_out_one,
                                                                    unsigned int size_param_out_one)
{
    double sum = 0;
    for (unsigned int i=0;i<size_param_out_one && i < size_param_in_one;i++)
    {
        table_param_out_one[i] = (int)table_param_in_one[i];
        sum += table_param_in_one[i];
    }
    return sum;
}

bool one_table_in_one_table_out_params_bool_return_function( double* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_out_one,
                                                                unsigned int size_param_out_one)
{
    double sum = 0;
    for (unsigned int i=0;i<size_param_out_one && i < size_param_in_one;i++)
    {
        table_param_out_one[i] = (int)table_param_in_one[i];
        sum += table_param_in_one[i];
    }
    return sum < 100.0;
}

