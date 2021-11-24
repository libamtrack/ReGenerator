#ifndef __TABLES_PARAMS__
#define __TABLES_PARAMS__


/* -------------------- One table in, no out params ------------------------*/

/**
 * Prints new line characters on console.
 * 
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 *
 */
void one_table_in_no_out_params_no_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one);

/**
 * This functions sums table elements and rounds result to integer
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 *
 * @return sum of table_param_in_one elements rounded to integer
 */
int one_table_in_no_out_params_int_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one);

/**
 * This functions sums table elements, takes absolute value of result and rounds it to integer
 * @see one_table_in_no_out_params_int_return_function
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 *
 * @return absolute value of sum of table_param_in_one elements rounded to integer
 */
unsigned int one_table_in_no_out_params_unsigned_int_return_function( double* table_param_in_one,
                                                                        unsigned int size_param_in_one);

/**
 * This functions sums elements of table_param_in_one
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 *
 * @return sums of table_param_in_one
 */
float one_table_in_no_out_params_float_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one);

/**
 * This functions sums elements of table_param_in_one
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 *
 * @return sums of table_param_in_one
 */
double one_table_in_no_out_params_double_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one);

/**
 * This functions checks if sum of table_param_in_one elemets is less than 100
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 *
 * @return boolean value telling if sum of table_param_in_one elements is less than 100
 */
bool one_table_in_no_out_params_bool_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one);


/* -------------------- No in params, one table out ------------------------*/

/**
 * This functions sets all table_param_out_one elements to 10
 * 
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 */
void no_in_one_table_out_params_no_return_function( double* table_param_out_one,
                                                    unsigned int size_param_out_one);

/**
 * This functions sets all table_param_out_one elements to -10 and returns a sum of them
 *
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of table_param_out_one elements = size_param_out_one * (-10)
 */
int no_in_one_table_out_params_int_return_function( double* table_param_out_one,
                                                    unsigned int size_param_out_one);

/**
 * This functions sets all table_param_out_one elements to 10 and returns a sum of them
 *
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of table_param_out_one elements = size_param_out_one * 10
 */
unsigned int no_in_one_table_out_params_unsigned_int_return_function( double* table_param_out_one,
                                                                        unsigned int size_param_out_one);

/**
 * This functions sets all table_param_out_one elements to 10.2 and returns a sum of them
 *
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of table_param_out_one elements = size_param_out_one * 10.2
 */
float no_in_one_table_out_params_float_return_function( double* table_param_out_one,
                                                        unsigned int size_param_out_one);

/**
 * This functions sets all table_param_out_one elements to 10.2 and returns a sum of them
 *
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of table_param_out_one elements = size_param_out_one * 10.2
 */
double no_in_one_table_out_params_double_return_function( double* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * This functions sets all table_param_out_one elements to 10.2 and checks if sum is less than 100
 *
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return boolean value telling if sum of set elements is less than 100
 */
bool no_in_one_table_out_params_bool_return_function( double* table_param_out_one,
                                                        unsigned int size_param_out_one);


/* -------------------- One table in, one param out ------------------------*/

/**
 * Sets param_out_one value to be a sum of table_param_in_one elements
 * 
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] param_out_one first out param
 *
 */
void one_table_in_one_out_param_no_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one,
                                                    float* param_out_one);

/**
 * Sets param_out_one value to be a sum of table_param_in_one elements and returns that value rounded to integer.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] param_out_one first out param
 *
 * @return sum of table_param_in elements rounded to integer
 */
int one_table_in_one_out_param_int_return_function( double* table_param_in_one,
                                                    unsigned int size_param_in_one,
                                                    float* param_out_one);

/**
 * Sets param_out_one value to be a sum of table_param_in_one elements and returns absolute value of it rounded to integer.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] param_out_one first out param
 *
 * @return absolute value of sum of table_param_in elements rounded to integer
 */
unsigned int one_table_in_one_out_param_unsigned_int_return_function( double* table_param_in_one,
                                                                        unsigned int size_param_in_one,
                                                                        float* param_out_one);

/**
 * Sets param_out_one value to be a sum of table_param_in_one elements and returns it.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] param_out_one first out param
 *
 * @return sum of table_param_in_one elements
 */
float one_table_in_one_out_param_float_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one,
                                                        float* param_out_one);

/**
 * Sets param_out_one value to be a sum of table_param_in_one elements and returns it.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] param_out_one first out param
 *
 * @return sum of table_param_in_one elements
 */
double one_table_in_one_out_param_double_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            float* param_out_one);

/**
 * Sets param_out_one value to be a sum of table_param_in_one elements and checks if that sum is less than 100.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] param_out_one first out param
 *
 * @return boolean value telling if sum of table_param_in_one elements is less than 100
 */
bool one_table_in_one_out_param_bool_return_function( double* table_param_in_one,
                                                        unsigned int size_param_in_one,
                                                        float* param_out_one);


/* -------------------- One in param, one table out ------------------------*/

/**
 * Sets elements of table_param_out_one to be equal to param_in_one.
 * 
 * @param[in] param_in_one first in param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 */
void one_param_in_one_table_out_no_return_function( double param_in_one,
                                                        double* table_param_out_one,
                                                        unsigned int size_param_out_one);

/**
 * Sets elements of table_param_out_one to be equal to param_in_one, sums it, negates and round to integer.
 *
 * @param[in] param_in_one first in param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return negation of sum of table_param_out_one elements rounded to integer
 */
int one_param_in_one_table_out_params_int_return_function( double param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * Sets elements of table_param_out_one to be equal to param_in_one, sums it and rounds to integer.
 *
 * @param[in] param_in_one first in param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return absolute value of sum of table_param_out_in rounded to integer
 */
unsigned int one_param_in_one_table_out_unsigned_int_return_function( double param_in_one,
                                                                        double* table_param_out_one,
                                                                            unsigned int size_param_out_one);

/**
 * Sets elements of table_param_out_one to be equal to param_in_one and sums it.
 *
 * @param[in] param_in_one first in param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum if table_param_out_one elements
 */
float one_param_in_one_table_out_float_return_function( double param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * Sets elements of table_param_out_one to be equal to param_in_one and sums it.
 *
 * @param[in] param_in_one first in param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum if table_param_out_one elements
 */
double one_param_in_one_table_out_double_return_function( double param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * Sets elements of table_param_out_one to be equal to param_in_one, sums it and checks if it is less than size_param_out_one.
 *
 * @param[in] param_in_one first in param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return boolean value telling if sum of table_param_out_one elements is less than size_param_out_one
 */
bool one_param_in_one_table_out_bool_return_function( double param_in_one,
                                                        double* table_param_out_one,
                                                        unsigned int size_param_out_one);


/* -------------------- One table in, one table out params ------------------------*/

/**
 * Writes elements of table_param_in_one to table_param_out_one rounded to integer.
 * 
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 */
void one_table_in_one_table_out_params_no_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            int* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * Writes elements of table_param_in_one to table_param_out_one rounded to integer and returns sum of written elements rounded to integer.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of written elements to table_param_out_one rounded to integer
 */
int one_table_in_one_table_out_params_int_return_function( double* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            int* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * Writes elements of table_param_in_one to table_param_out_one rounded to integer and returns absolute value sum of written elements rounded to integer.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return absolute value sum of written elements to table_param_out_one rounded to integer
 */
unsigned int one_table_in_one_table_out_params_unsigned_int_return_function( double* table_param_in_one,
                                                                                unsigned int size_param_in_one,
                                                                                int* table_param_out_one,
                                                                                unsigned int size_param_out_one);

/**
 * Writes elements of table_param_in_one to table_param_out_one rounded to integer and returns sum of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of written elements
 */
float one_table_in_one_table_out_params_float_return_function( double* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_out_one,
                                                                unsigned int size_param_out_one);

/**
 * Writes elements of table_param_in_one to table_param_out_one rounded to integer and returns sum of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of written elements
 */
double one_table_in_one_table_out_params_double_return_function( double* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    int* table_param_out_one,
                                                                    unsigned int size_param_out_one);

/**
 * Writes elements of table_param_in_one to table_param_out_one rounded to integer and checks if sum if written elements is less than 100.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return boolean value telling if sum written elements is less than 100
 */
bool one_table_in_one_table_out_params_bool_return_function( double* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_out_one,
                                                                unsigned int size_param_out_one);


/* -------------------- Two tables in, one table out params ------------------------*/

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one.
 * 
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 */
void two_tables_in_one_table_out_params_no_return_function( float* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            int* table_param_in_two,
                                                            unsigned int size_param_in_two,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns number of written elements
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return number of written elements
 */
int two_tables_in_one_table_out_params_int_return_function( float* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            int* table_param_in_two,
                                                            unsigned int size_param_in_two,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns number of written elements
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return number of written elements
 */
unsigned int two_tables_in_one_table_out_params_unsigned_int_return_function( float* table_param_in_one,
                                                                                unsigned int size_param_in_one,
                                                                                int* table_param_in_two,
                                                                                unsigned int size_param_in_two,
                                                                                double* table_param_out_one,
                                                                                unsigned int size_param_out_one);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns sum of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of written elements
 */
float two_tables_in_one_table_out_params_float_return_function( float* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_in_two,
                                                                unsigned int size_param_in_two,
                                                                double* table_param_out_one,
                                                                unsigned int size_param_out_one);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns sum of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return sum of written elements
 */
double two_tables_in_one_table_out_params_double_return_function( float* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    int* table_param_in_two,
                                                                    unsigned int size_param_in_two,
                                                                    double* table_param_out_one,
                                                                    unsigned int size_param_out_one);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and checks if table_param_out_one was filled
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 *
 * @return boolean value telling if number of written elements is equal to size_param_out_one
 */
bool two_tables_in_one_table_out_params_bool_return_function( float* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_in_two,
                                                                unsigned int size_param_in_two,
                                                                double* table_param_out_one,
                                                                unsigned int size_param_out_one);


/* -------------------- One table in, two tables out params ------------------------*/


/**
 * Writes elements of table_param_in_one to table_param_out_one and to table_param_out_two rounded to integer.
 * 
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 */
void one_table_in_two_tables_out_params_no_return_function( float* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one,
                                                            int* table_param_out_two,
                                                            unsigned int size_param_out_two);

/**
 * Writes elements of table_param_in_one to table_param_out_one and to table_param_out_two rounded to integer and returns max number of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return max of number of written elements to table_param_out_one and table_param_out_two
 */
int one_table_in_two_tables_out_params_int_return_function( float* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param_out_one,
                                                            int* table_param_out_two,
                                                            unsigned int size_param_out_two);

/**
 * Writes elements of table_param_in_one to table_param_out_one and to table_param_out_two rounded to integer and returns max number of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return max of number of written elements to table_param_out_one and table_param_out_two
 */
unsigned int one_table_in_two_tables_out_params_unsigned_int_return_function( float* table_param_in_one,
                                                                                unsigned int size_param_in_one,
                                                                                double* table_param_out_one,
                                                                                unsigned int size_param_out_one,
                                                                                int* table_param_out_two,
                                                                                unsigned int size_param_out_two);

/**
 * Writes elements of table_param_in_one to table_param_out_one and to table_param_out_two rounded to integer and returns max sum of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return max value of sum of written elements to table_param_out_one and table_param_out_two
 */
float one_table_in_two_tables_out_params_float_return_function( float* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                double* table_param_out_one,
                                                                unsigned int size_param_out_one,
                                                                int* table_param_out_two,
                                                                unsigned int size_param_out_two);

/**
 * Writes elements of table_param_in_one to table_param_out_one and to table_param_out_two rounded to integer and returns max sum of written elements.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return max value of sum of written elements to table_param_out_one and table_param_out_two
 */
double one_table_in_two_tables_out_params_double_return_function( float* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    double* table_param_out_one,
                                                                    unsigned int size_param_out_one,
                                                                    int* table_param_out_two,
                                                                    unsigned int size_param_out_two);

/**
 * Writes elements of table_param_in_one to table_param_out_one and to table_param_out_two rounded to integer and checks if table_param_out_one and table_param_out_two were filled.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return boolean value telling if max number of written elements is equal to size_param_out_one and size_param_out_two
 */
bool one_table_in_two_tables_out_params_bool_return_function( float* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                double* table_param_out_one,
                                                                unsigned int size_param_out_one,
                                                                int* table_param_out_two,
                                                                unsigned int size_param_out_two);


/* -------------------- Two tables in, two tables out params ------------------------*/


/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and sets string to table_param_out_two.
 * 
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 */
void two_tables_in_two_tables_out_params_no_return_function( float* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_in_two,
                                                                unsigned int size_param_in_two,
                                                                double* table_param_out_one,
                                                                unsigned int size_param_out_one,
                                                                char* table_param_out_two,
                                                                unsigned int size_param_out_two);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns number of written elements and sets string to table_param_out_two.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return number of written elements
 */
int two_tables_in_two_tables_out_params_int_return_function( float* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_in_two,
                                                                unsigned int size_param_in_two,
                                                                double* table_param_out_one,
                                                                unsigned int size_param_out_one,
                                                                char* table_param_out_two,
                                                                unsigned int size_param_out_two);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns number of written elements and sets string to table_param_out_two.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return number of written elements
 */
unsigned int two_tables_in_two_tables_out_params_unsigned_int_return_function( float* table_param_in_one,
                                                                                unsigned int size_param_in_one,
                                                                                int* table_param_in_two,
                                                                                unsigned int size_param_in_two,
                                                                                double* table_param_out_one,
                                                                                unsigned int size_param_out_one,
                                                                                char* table_param_out_two,
                                                                                unsigned int size_param_out_two);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns sum of written elements and sets string to table_param_out_two.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return sum of written elements
 */
float two_tables_in_two_tables_out_params_float_return_function( float* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    int* table_param_in_two,
                                                                    unsigned int size_param_in_two,
                                                                    double* table_param_out_one,
                                                                    unsigned int size_param_out_one,
                                                                    char* table_param_out_two,
                                                                    unsigned int size_param_out_two);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and returns sum of written elements and sets string to table_param_out_two.
 *
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return sum of written elements
 */
double two_tables_in_two_tables_out_params_double_return_function( float* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    int* table_param_in_two,
                                                                    unsigned int size_param_in_two,
                                                                    double* table_param_out_one,
                                                                    unsigned int size_param_out_one,
                                                                    char* table_param_out_two,
                                                                    unsigned int size_param_out_two);

/**
 * Writes sums elements of table_param_in_one and table_param_in_two to table_param_out_one and checks if table_param_out_one was filled
 * and sets string to table_param_out_two.
 * 
 * @param[in] table_param_in_one first table in param (array of size size_param_in_one)
 * @param[in] size_param_in_one size of first in table param
 * @param[in] table_param_in_two second table in param (array of size size_param_in_two)
 * @param[in] size_param_in_two size of second in table param
 * @param[out] table_param_out_one first table out param (array of size size_param_out_one)
 * @param[out] size_param_out_one size of first table out param
 * @param[out] table_param_in_two second table out param (array of size size_param_out_two)
 * @param[out] size_param_in_two size of second out table param
 *
 * @return boolean value telling if number of written elements is equal to size_param_out_one
 */
bool two_tables_in_two_tables_out_params_bool_return_function( float* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                int* table_param_in_two,
                                                                unsigned int size_param_in_two,
                                                                double* table_param_out_one,
                                                                unsigned int size_param_out_one,
                                                                char* table_param_out_two,
                                                                unsigned int size_param_out_two);


#endif