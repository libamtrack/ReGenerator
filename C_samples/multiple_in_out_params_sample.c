#include <stdio.h>
#include <stdbool.h>

#include "multiple_in_out_params_sample.h"
#include <math.h>


/* -------------------- One in, two out params ------------------------*/

void one_in_two_out_params_no_return_function(int param_in, double* param_out_one, float* param_out_two)
{
    printf("%d, %f, %f\r\n", param_in, *param_out_one, *param_out_two);
    *param_out_one = 10.0 * param_in;
    *param_out_two = param_in / 10.0;
}

int one_in_two_out_params_int_return_function(int param_in, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in;
    *param_out_two = param_in / 10.0;
    return -1 * param_in;
}

unsigned int one_in_two_out_params_unsigned_int_return_function(int param_in, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in;
    *param_out_two = param_in / 10.0;
    return abs(10 * param_in);
}

float one_in_two_out_params_float_return_function(int param_in, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in;
    *param_out_two = param_in / 10.0;
    return 1.2 * param_in;
}

double one_in_two_out_params_double_return_function(int param_in, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in;
    *param_out_two = param_in / 10.0;
    return 0.5 * param_in;
}

bool one_in_two_out_params_bool_return_function(int param_in, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in;
    *param_out_two = param_in / 10.0;
    return param_in > 10;
}


/* -------------------- Two in, two out params ------------------------*/

void two_in_two_out_params_no_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two)
{
    printf("%d, %c, %f, %f\r\n", param_in_one, param_in_two, *param_out_one, *param_out_two);
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
}

int two_in_two_out_params_int_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    return -1 * (param_in_one + (int)param_in_two);
}

unsigned int two_in_two_out_params_unsigned_int_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    return abs( 10 * (param_in_one + (int)param_in_two));
}

float two_in_two_out_params_float_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    return 1.2 * (param_in_one + (int)param_in_two);
}

double two_in_two_out_params_double_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    return 0.5 * (param_in_one + (int)param_in_two);
}

bool two_in_two_out_params_bool_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    return param_in_one > 10 || param_in_two == 'p';
}


/* -------------------- Two in, three out params ------------------------*/

void two_in_three_out_params_no_return_function(    int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three)
{
    printf("%d, %c, %f, %f, %u\r\n", param_in_one, param_in_two, *param_out_one, *param_out_two, *param_out_three);
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
}

int two_in_three_out_params_int_return_function(    int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
    return -1 * (param_in_one + (int)param_in_two);
}

unsigned int two_in_three_out_params_unsigned_int_return_function(  int param_in_one, 
                                                                    char param_in_two,
                                                                    double* param_out_one, 
                                                                    float* param_out_two, 
                                                                    unsigned int* param_out_three)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
    return abs( 10 * (param_in_one + (int)param_in_two) );
}

float two_in_three_out_params_float_return_function(    int param_in_one, 
                                                        char param_in_two, 
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
    return 1.2 * (param_in_one + (int)param_in_two);
}

double two_in_three_out_params_double_return_function(  int param_in_one, 
                                                        char param_in_two, 
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
    return 0.5 * (param_in_one + (int)param_in_two);
}

bool two_in_three_out_params_bool_return_function(  int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three)
{
    *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
    *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
    *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
    return param_in_one > 10 || param_in_two == 'p';
}


/* -------------------- Three in, three out params ------------------------*/

void three_in_three_out_params_no_return_function(  int param_in_one, 
                                                    char param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three)
{
    printf("%d, %c, %u, %f, %f, %u\r\n", param_in_one, param_in_two, param_in_three, *param_out_one, *param_out_two, *param_out_three);
    if (param_in_three)
    {
        *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
    }
    else
    {
        *param_out_one = param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) + (unsigned int)param_in_two;
    }
}

int three_in_three_out_params_int_return_function(  int param_in_one, 
                                                    char param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three)
{
    if (param_in_three)
    {
        *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
        return -1 * (param_in_one + (int)param_in_two);
    }
    else 
    {
        *param_out_one = param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) + (unsigned int)param_in_two;
        return (param_in_one + (unsigned int)param_in_two);
    }
}

unsigned int three_in_three_out_params_unsigned_int_return_function(    int param_in_one, 
                                                                        char param_in_two,
                                                                        const bool param_in_three,
                                                                        double* param_out_one, 
                                                                        float* param_out_two, 
                                                                        unsigned int* param_out_three)
{
    if (param_in_three)
    {
        *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
        return abs( 10 * (param_in_one + (unsigned int)param_in_two));
    }
    else 
    {
        *param_out_one = param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) + (unsigned int)param_in_two;
        return abs( (param_in_one + (unsigned int)param_in_two));
    }
}

float three_in_three_out_params_float_return_function(  int param_in_one, 
                                                        char param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three)
{
    if (param_in_three)
    {
        *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
        return 1.2 * (param_in_one + (int)param_in_two);    
    }
    else
    {
        *param_out_one = param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) + (unsigned int)param_in_two;
        return param_in_one + (int)param_in_two;
    }
}

double three_in_three_out_params_double_return_function(    int param_in_one, 
                                                            char param_in_two,
                                                            const bool param_in_three,
                                                            double* param_out_one, 
                                                            float* param_out_two, 
                                                            unsigned int* param_out_three)
{
    if (param_in_three)
    {
        *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
        return 0.5 * (param_in_one + (int)param_in_two);
    }
    else
    {
        *param_out_one = param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) + (unsigned int)param_in_two;
        return param_in_one + (int)param_in_two;
    }
}

bool three_in_three_out_params_bool_return_function(    int param_in_one, 
                                                        char param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three)
{
    if (param_in_three)
    {
        *param_out_one = 10.0 * param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one / 10.0 + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) / 2 + (unsigned int)param_in_two;
    }
    else
    {
        *param_out_one = param_in_one + (unsigned int)param_in_two;
        *param_out_two = param_in_one + (unsigned int)param_in_two;
        *param_out_three = abs(param_in_one) + (unsigned int)param_in_two;
    }
    return param_in_one > 10 || (param_in_two == 'p' && param_in_three);
}

