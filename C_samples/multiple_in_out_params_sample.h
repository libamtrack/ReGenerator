#ifndef __MULT_OUT_PARAMS__
#define __MULT_OUT_PARAMS__

/* -------------------- One in, two out params ------------------------*/

/**
 * Prints new line characters on console.
 * To param_out_one is assigned value of param_in multiplied by 10 
 * and to param_out_two is assigned value of param_in divided by 10.
 * 
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 */
void one_in_two_out_params_no_return_function(int param_in, double* param_out_one, float* param_out_two);

/**
 * This functions returns param_in value multiplied by -1.
 * To param_out_one is assigned value of param_in multiplied by 10 
 * and to param_out_two is assigned value of param_in divided by 10.
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return param_in value multiplied by -1.
 */
int one_in_two_out_params_int_return_function(int param_in, double* param_out_one, float* param_out_two);

/**
 * This functions returns absolute value of param_in multiplied by 10.
 * To param_out_one is assigned value of param_in multiplied by 10 
 * and to param_out_two is assigned value of param_in divided by 10.
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return absolute value of param_in multiplied by 10.
 */
unsigned int one_in_two_out_params_unsigned_int_return_function(int param_in, double* param_out_one, float* param_out_two);

/**
 * This functions returns param_in value multiplied by 1.2.
 * To param_out_one is assigned value of param_in multiplied by 10 
 * and to param_out_two is assigned value of param_in divided by 10.
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return param_in value multiplied by 1.2.
 */
float one_in_two_out_params_float_return_function(int param_in, double* param_out_one, float* param_out_two);

/**
 * This functions returns param_in value multiplied by 0.5.
 * To param_out_one is assigned value of param_in multiplied by 10 
 * and to param_out_two is assigned value of param_in divided by 10.
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return param_in value multiplied by 0.5.
 */
double one_in_two_out_params_double_return_function(int param_in, double* param_out_one, float* param_out_two);

/**
 * This functions returns boolean value telling if param_in is greater that 10.
 * To param_out_one is assigned value of param_in multiplied by 10 
 * and to param_out_two is assigned value of param_in divided by 10.
 *
 * @param[in] param_in first in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return boolean value telling if param_in is greater that 10.
 */
bool one_in_two_out_params_bool_return_function(int param_in, double* param_out_one, float* param_out_two);


/* -------------------- Two in, two out params ------------------------*/

/**
 * Prints new line characters on console.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 * 
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 */
void two_in_two_out_params_no_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by -1.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return sum of param_in_one and param_in_two multiplied by -1.
 */
int two_in_two_out_params_int_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two);

/**
 * This functions returns absolute value of sum of param_in_one and param_in_two multiplied by 10.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return absolute value of sum of param_in_one and param_in_two multiplied by 10
 */
unsigned int two_in_two_out_params_unsigned_int_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two);

/**
 * This functions returns  sum of param_in_one and param_in_two multiplied by 1.2.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return sum of param_in_one and param_in_two multiplied by 1.2.
 */
float two_in_two_out_params_float_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two);

/**
 * This functions returns  sum of param_in_one and param_in_two multiplied by 0.5.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return sum of param_in_one and param_in_two multiplied by 0.5.
 */
double two_in_two_out_params_double_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two);

/**
 * This functions checks if param_in_one is greater than 10 or param_in_two is a 'p' character.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 *
 * @return boolean value telling if param_in_one is greater than 10 or param_in_two is a 'p' character.
 */
bool two_in_two_out_params_bool_return_function(int param_in_one, char param_in_two, double* param_out_one, float* param_out_two);


/* -------------------- Two in, three out params ------------------------*/

/**
 * Prints new line characters on console.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two.
 * 
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 */
void two_in_three_out_params_no_return_function(    int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by -1.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return sum of param_in_one and param_in_two multiplied by -1.
 */
int two_in_three_out_params_int_return_function(    int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions returns absolute value of sum of param_in_one and param_in_two multiplied by 10.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return absolute value of sum of param_in_one and param_in_two multiplied by 10.
 */
unsigned int two_in_three_out_params_unsigned_int_return_function(  int param_in_one, 
                                                                    char param_in_two,
                                                                    double* param_out_one, 
                                                                    float* param_out_two, 
                                                                    unsigned int* param_out_three);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by 1.2.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return sum of param_in_one and param_in_two multiplied by 1.2.
 */
float two_in_three_out_params_float_return_function(    int param_in_one, 
                                                        char param_in_two, 
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by 0.5.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return sum of param_in_one and param_in_two multiplied by 0.5.
 */
double two_in_three_out_params_double_return_function(  int param_in_one, 
                                                        char param_in_two, 
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three);

/**
 * This functions checks if param_in_one is greater than 10 or param_in_two is a 'p' character.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return boolean value telling if param_in_one is greater than 10 or param_in_two is a 'p' character.
 */
bool two_in_three_out_params_bool_return_function(  int param_in_one, 
                                                    char param_in_two, 
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three);


/* -------------------- Three in, three out params ------------------------*/

/**
 * Prints new line characters on console.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two if param_in_three is true.
 * If param_int_three is false, values assigned to out params and returned value are not multiplied nor divided by constansts.
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
                                                    char param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by -1 if param_in_three is true.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two if param_in_three is true.
 * If param_int_three is false, values assigned to out params and returned value are not multiplied nor divided by constansts.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return sum of param_in_one and param_in_two multiplied by -1 if param_in_three is true. Otherwise, sum of param_in_one and param_in_two.
 */
int three_in_three_out_params_int_return_function(  int param_in_one, 
                                                    char param_in_two,
                                                    const bool param_in_three,
                                                    double* param_out_one, 
                                                    float* param_out_two, 
                                                    unsigned int* param_out_three);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by 10 if param_in_three is true.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two if param_in_three is true.
 * If param_int_three is false, values assigned to out params and returned value are not multiplied nor divided by constansts.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return sum of param_in_one and param_in_two multiplied by 10 if param_in_three is true. Otherwise, sum of param_in_one and param_in_two.
 */
unsigned int three_in_three_out_params_unsigned_int_return_function(    int param_in_one, 
                                                                        char param_in_two,
                                                                        const bool param_in_three,
                                                                        double* param_out_one, 
                                                                        float* param_out_two, 
                                                                        unsigned int* param_out_three);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by 1.2 if param_in_three is true.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two if param_in_three is true.
 * If param_int_three is false, values assigned to out params and returned value are not multiplied nor divided by constansts.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return sum of param_in_one and param_in_two multiplied by 1.2 if param_in_three is true. Otherwise, sum of param_in_one and param_in_two.
 */
float three_in_three_out_params_float_return_function(  int param_in_one, 
                                                        char param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three);

/**
 * This functions returns sum of param_in_one and param_in_two multiplied by 0.5 if param_in_three is true.
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two if param_in_three is true.
 * If param_int_three is false, values assigned to out params and returned value are not multiplied nor divided by constansts.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return sum of param_in_one and param_in_two multiplied by 0.5 if param_in_three is true. Otherwise, sum of param_in_one and param_in_two.
 */
double three_in_three_out_params_double_return_function(    int param_in_one, 
                                                            char param_in_two,
                                                            const bool param_in_three,
                                                            double* param_out_one, 
                                                            float* param_out_two, 
                                                            unsigned int* param_out_three);

/**
 * This functions checks if param_in_one is greater than 10 or (param_in_two is a 'p' character and param_in_three is true).
 * To param_out_one is assigned value of param_in_one multiplied by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_two is assigned value of param_in_one divided by 10 plus integer value of param_in_two if param_in_three is true.
 * To param_out_three is assigned value of param_in_one rounded to integer and divided by 2 plus integer value of param_in_two if param_in_three is true.
 * If param_int_three is false, values assigned to out params are not multiplied nor divided by constansts.
 *
 * @param[in] param_in_one first in param
 * @param[in] param_in_two second in param
 * @param[in] param_in_three third in param
 * @param[out] param_out_one first out param
 * @param[out] param_out_two second out param
 * @param[out] param_out_three third out param
 *
 * @return boolean value telling if param_in_one is greater than 10 or (param_in_two is a 'p' character and param_in_three is true).
 */
bool three_in_three_out_params_bool_return_function(    int param_in_one, 
                                                        char param_in_two,
                                                        const bool param_in_three,
                                                        double* param_out_one, 
                                                        float* param_out_two, 
                                                        unsigned int* param_out_three);

#endif
