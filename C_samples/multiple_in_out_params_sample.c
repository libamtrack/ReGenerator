#include <stdio.h>
#include <stdbool.h>

#include "multiple_in_out_params_sample.h"
#include <math.h>


/* -------------------- One in, two out params ------------------------*/

void one_in_two_out_params_no_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    printf("\r\n");
}

int one_in_two_out_params_int_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return -1 * param_in;
}

unsigned int one_in_two_out_params_unsigned_int_return_function(int param_in, double* param_out_one, char* param_out_two)
{
<<<<<<< HEAD
    return abs(10 * param_in);
=======
    return 10 * param_in;
>>>>>>> origin
}

float one_in_two_out_params_float_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return 1.2 * param_in;
}

double one_in_two_out_params_double_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return 0.5 * param_in;
}

bool one_in_two_out_params_bool_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return param_in > 10;
}


/* -------------------- Two in, two out params ------------------------*/

void two_in_two_out_params_no_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two)
{
    printf("\r\n");
}

int two_in_two_out_params_int_return_function(int param_in_one, char param_in_two, double* param_out_one, char* param_out_two)
{
    return -1 * (param_in_one + (int)param_in_two);
}

unsigned int two_in_two_out_params_unsigned_int_return_function(int param_in_one, char param_in_two, double* param_out_one, char* param_out_two)
{
<<<<<<< HEAD
    return abs( 10 * (param_in_one + (int)param_in_two));
=======
    return 10 * (param_in_one + (int)param_in_two);
>>>>>>> origin
}

float two_in_two_out_params_float_return_function(int param_in_one, char param_in_two, double* param_out_one, char* param_out_two)
{
    return 1.2 * (param_in_one + (int)param_in_two);
}

double two_in_two_out_params_double_return_function(int param_in_one, char param_in_two, double* param_out_one, char* param_out_two)
{
    return 0.5 * (param_in_one + (int)param_in_two);
}

bool two_in_two_out_params_bool_return_function(int param_in_one, char param_in_two, double* param_out_one, char* param_out_two)
{
    return param_in_one > 10 || param_in_two == 'p';
}


/* -------------------- Two in, three out params ------------------------*/

void two_in_three_out_params_no_return_function(    int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    printf("\r\n");
}

int two_in_three_out_params_int_return_function(    int param_in_one, 
                                                    char* param_in_two, 
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    return -1 * (param_in_one + (int)param_in_two);
}

unsigned int two_in_three_out_params_unsigned_int_return_function(  int param_in_one, 
                                                                    char param_in_two,
                                                                    double* param_out_one, 
                                                                    char* param_out_two, 
                                                                    unsigned int* param_out_three)
{
<<<<<<< HEAD
    return abs( 10 * (param_in_one + (int)param_in_two) );
=======
    return 10 * (param_in_one + (int)param_in_two);
>>>>>>> origin
}

float two_in_three_out_params_float_return_function(    int param_in_one, 
                                                        char param_in_two, 
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    return 1.2 * (param_in_one + (int)param_in_two);
}

double two_in_three_out_params_double_return_function(  int param_in_one, 
                                                        char* param_in_two, 
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    return 0.5 * (param_in_one + (int)param_in_two);
}

bool two_in_three_out_params_bool_return_function(  int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    return param_in_one > 10 || param_in_two == 'p';
}


/* -------------------- Three in, three out params ------------------------*/

void three_in_three_out_params_no_return_function(  int param_in_one, 
                                                    char param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    printf("\r\n");
}

int three_in_three_out_params_int_return_function(  int param_in_one, 
                                                    char param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    if (param_in_three)
    {
        return -1 * (param_in_one + (int)param_in_two);
    }
    else 
    {
        return (param_in_one + (int)param_in_two);
    }
}

unsigned int three_in_three_out_params_unsigned_int_return_function(    int param_in_one, 
                                                                        char param_in_two,
                                                                        const bool param_in_three,
                                                                        double* param_out_one, 
                                                                        char* param_out_two, 
                                                                        unsigned int* param_out_three)
{
<<<<<<< HEAD
    return abs( 10 * (param_in_one + (int)param_in_two) * (5 + (int)param_in_three) );
=======
    return 10 * (param_in_one + (int)param_in_two) * (5 + (int)param_in_three);
>>>>>>> origin
}

float three_in_three_out_params_float_return_function(  int param_in_one, 
                                                        char param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    if (param_in_three)
    {
        return 1.2 * (param_in_one + (int)param_in_two);    
    }
    else
    {
        return -1.2 * (param_in_one + (int)param_in_two);
    }
}

double three_in_three_out_params_double_return_function(    int param_in_one, 
                                                            char param_in_two,
                                                            const bool param_in_three,
                                                            double* param_out_one, 
                                                            char* param_out_two, 
                                                            unsigned int* param_out_three)
{
    if (param_in_three)
    {
        return 0.5 * (param_in_one + (int)param_in_two);
    }
    else
    {
        return -0.5 * (param_in_one + (int)param_in_two);
    }
}

bool three_in_three_out_params_bool_return_function(    int param_in_one, 
                                                        char param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    return param_in_one > 10 || (param_in_two == 'p' && param_in_three);
}

