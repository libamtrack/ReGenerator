#ifndef __TABLES_PARAMS__
#define __TABLES_PARAMS__

/* -------------------- One table in, one table out params ------------------------*/

/**
 * Prints new line characters on console.
 * 
 * @param[in] table_param_in_one first table in param
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param
 * @param[out] size_param__out_one size of first table out param
 *
 */
void one_table_in_one_table_out_params_no_return_function( char* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param__out_one);

/**
 * This functions always returns -1
 *
 * @param[in] table_param_in_one first table in param
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param
 * @param[out] size_param__out_one size of first table out param
 *
 * @return status code
 */
int one_table_in_one_table_out_params_int_return_function( char* table_param_in_one,
                                                            unsigned int size_param_in_one,
                                                            double* table_param_out_one,
                                                            unsigned int size_param__out_one);

/**
 * This functions always returns 10
 *
 * @param[in] table_param_in_one first table in param
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param
 * @param[out] size_param__out_one size of first table out param
 *
 * @return status code
 */
unsigned int one_table_in_one_table_out_params_unsigned_int_return_function( char* table_param_in_one,
                                                                                unsigned int size_param_in_one,
                                                                                double* table_param_out_one,
                                                                                unsigned int size_param__out_one);

/**
 * This functions always returns 1.2
 *
 * @param[in] table_param_in_one first table in param
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param
 * @param[out] size_param__out_one size of first table out param
 *
 * @return dummy number
 */
float one_table_in_one_table_out_params_float_return_function( char* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                double* table_param_out_one,
                                                                unsigned int size_param__out_one);

/**
 * This functions always returns 0.5
 *
 * @param[in] table_param_in_one first table in param
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param
 * @param[out] size_param__out_one size of first table out param
 *
 * @return dummy number
 */
double one_table_in_one_table_out_params_double_return_function( char* table_param_in_one,
                                                                    unsigned int size_param_in_one,
                                                                    double* table_param_out_one,
                                                                    unsigned int size_param__out_one);

/**
 * This functions always returns true
 *
 * @param[in] table_param_in_one first table in param
 * @param[in] size_param_in_one size of first in table param
 * @param[out] table_param_out_one first table out param
 * @param[out] size_param__out_one size of first table out param
 *
 * @return status code
 */
bool one_table_in_one_table_out_params_bool_return_function( char* table_param_in_one,
                                                                unsigned int size_param_in_one,
                                                                double* table_param_out_one,
                                                                unsigned int size_param__out_one);


#endif