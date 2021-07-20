#ifndef __MULT_OUT_PARAMS__
#define __MULT_OUT_PARAMS__

/* -------------------- One in, two out params ------------------------*/

/**
 * Prints new line characters on console.
 * 
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 */
void one_in_two_out_params_no_return_function(int param_in, double* param_out_one, char* param_out_two);

/**
 * This functions always returns -1
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return status code
 */
int one_in_two_out_params_int_return_function(int param_in, double* param_out_one, char* param_out_two);

/**
 * This functions always returns 10
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return status code
 */
unsigned int one_in_two_out_params_unsigned_int_return_function(int param_in, double* param_out_one, char* param_out_two);

/**
 * This functions always returns 1.2
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return dummy number
 */
float one_in_two_out_params_float_return_function(int param_in, double* param_out_one, char* param_out_two);

/**
 * This functions always returns 0.5
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return dummy number
 */
double one_in_two_out_params_double_return_function(int param_in, double* param_out_one, char* param_out_two);

/**
 * This functions always returns true
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return status code
 */
bool one_in_two_out_params_bool_return_function(int param_in, double* param_out_one, char* param_out_two);


/* -------------------- Two in, two out params ------------------------*/

/**
 * Prints new line characters on console.
 * 
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 */
void two_in_two_out_params_no_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two);

/**
 * This functions always returns -1
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return status code
 */
int two_in_two_out_params_int_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two);

/**
 * This functions always returns 10
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return status code
 */
unsigned int two_in_two_out_params_unsigned_int_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two);

/**
 * This functions always returns 1.2
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return dummy number
 */
float two_in_two_out_params_float_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two);

/**
 * This functions always returns 0.5
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return dummy number
 */
double two_in_two_out_params_double_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two);

/**
 * This functions always returns true
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return status code
 */
bool two_in_two_out_params_bool_return_function(int param_in_one, char* param_in_two, double* param_out_one, char* param_out_two);


/* -------------------- Two in, three out params ------------------------*/

/**
 * Prints new line characters on console.
 * 
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 */
void two_in_three_out_params_no_return_function(    int param_in_one, 
                                                    char* param_in_two, 
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions always returns -1
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return status code
 */
int two_in_three_out_params_int_return_function(    int param_in_one, 
                                                    char* param_in_two, 
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions always returns 10
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return status code
 */
unsigned int two_in_three_out_params_unsigned_int_return_function(  int param_in_one, 
                                                                    char* param_in_two,
                                                                    double* param_out_one, 
                                                                    char* param_out_two, 
                                                                    unsigned int* param_out_three);

/**
 * This functions always returns 1.2
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return dummy number
 */
float two_in_three_out_params_float_return_function(    int param_in_one, 
                                                        char* param_in_two, 
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three);

/**
 * This functions always returns 0.5
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return dummy number
 */
double two_in_three_out_params_double_return_function(  int param_in_one, 
                                                        char* param_in_two, 
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three);

/**
 * This functions always returns true
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return status code
 */
bool two_in_three_out_params_bool_return_function(  int param_in_one, 
                                                    char* param_in_two, 
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three);


/* -------------------- Three in, three out params ------------------------*/

/**
 * Prints new line characters on console.
 * 
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 */
void three_in_three_out_params_no_return_function(  int param_in_one, 
                                                    char* param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions always returns -1
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return status code
 */
int three_in_three_out_params_int_return_function(  int param_in_one, 
                                                    char* param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    char* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions always returns 10
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return status code
 */
unsigned int three_in_three_out_params_unsigned_int_return_function(    int param_in_one, 
                                                                        char* param_in_two,
                                                                        const bool param_in_three,
                                                                        double* param_out_one, 
                                                                        char* param_out_two, 
                                                                        unsigned int* param_out_three);

/**
 * This functions always returns 1.2
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return dummy number
 */
float three_in_three_out_params_float_return_function(  int param_in_one, 
                                                        char* param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three);

/**
 * This functions always returns 0.5
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return dummy number
 */
double three_in_three_out_params_double_return_function(    int param_in_one, 
                                                            char* param_in_two,
                                                            const bool param_in_three,
                                                            double* param_out_one, 
                                                            char* param_out_two, 
                                                            unsigned int* param_out_three);

/**
 * This functions always returns true
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return status code
 */
bool three_in_three_out_params_bool_return_function(    int param_in_one, 
                                                        char* param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        char* param_out_two, 
                                                        unsigned int* param_out_three);


#endif
