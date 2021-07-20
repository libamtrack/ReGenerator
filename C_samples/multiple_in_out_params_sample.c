#include <stdio.h>
#include <stdbool.h>

#include "multiple_in_out_params_sample.h"


/* -------------------- One in, two out params ------------------------*/

void one_in_two_out_params_no_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    printf("\r\n");
}

int one_in_two_out_params_int_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return -1;
}

unsigned int one_in_two_out_params_unsigned_int_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return 10;
}

float one_in_two_out_params_float_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return 1.2;
}

double one_in_two_out_params_double_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return 0.5;
}

bool one_in_two_out_params_bool_return_function(int param_in, double* param_out_one, char* param_out_two)
{
    return true;
}


/* -------------------- Two in, two out params ------------------------*/

void two_in_two_out_params_no_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two)
{
    printf("\r\n");
}

int two_in_two_out_params_int_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two)
{
    return -1;
}

unsigned int two_in_two_out_params_unsigned_int_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two)
{
    return 10;
}

float two_in_two_out_params_float_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two)
{
    return 1.2;
}

double two_in_two_out_params_double_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two)
{
    return 0.5;
}

bool two_in_two_out_params_bool_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two)
{
    return true;
}


/* -------------------- Two in, three out params ------------------------*/

void two_in_three_out_params_no_return_function(    int param_in_one, 
                                                    char* param_in_two, 
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
    return -1;
}

unsigned int two_in_three_out_params_unsigned_int_return_function(  int param_in_one, 
                                                                    char* param_in_two,
                                                                    double* param_out_one, 
                                                                    char* param_out_two, 
                                                                    unsigned int* param_out_three)
{
    return 10;
}

float two_in_three_out_params_float_return_function(    int param_in_one, 
                                                        char* param_in_two, 
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    return 1.2;
}

double two_in_three_out_params_double_return_function(  int param_in_one, 
                                                        char* param_in_two, 
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    return 0.5;
}

bool two_in_three_out_params_bool_return_function(  int param_in_one, 
                                                    char* param_in_two, 
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    return true;
}


/* -------------------- Three in, three out params ------------------------*/

void three_in_three_out_params_no_return_function(  int param_in_one, 
                                                    char* param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    printf("\r\n");
}

int three_in_three_out_params_int_return_function(  int param_in_one, 
                                                    char* param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three)
{
    return -1;
}

unsigned int three_in_three_out_params_unsigned_int_return_function(    int param_in_one, 
                                                                        char* param_in_two,
                                                                        const bool param_in_three,
                                                                        double* param_out_one, 
                                                                        char* param_out_two, 
                                                                        unsigned int* param_out_three)
{
    return 10;
}

float three_in_three_out_params_float_return_function(  int param_in_one, 
                                                        char* param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    return 1.2;
}

double three_in_three_out_params_double_return_function(    int param_in_one, 
                                                            char* param_in_two,
                                                            const bool param_in_three,
                                                            double* param_out_one, 
                                                            char* param_out_two, 
                                                            unsigned int* param_out_three)
{
    return 0.5;
}

bool three_in_three_out_params_bool_return_function(    int param_in_one, 
                                                        char* param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three)
{
    return true;
}


