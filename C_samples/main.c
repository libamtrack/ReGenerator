#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "no_params_sample.h"
#include "only_in_params_sample.h"
#include "only_out_params_sample.h"
#include "one_in_one_out_param_sample.h"
#include "multiple_in_out_params_sample.h"
#include "tables_params_sample.h"

/* ------------ Testing functions declarations ---------------- */

void test_no_params_functions(void);
void test_one_in_no_out_params_functions(void);
void test_no_in_one_out_params_functions(void);
void test_one_in_one_out_params_functions(void);

void test_one_in_two_out_params_functions(void);
void test_two_in_two_out_params_functions(void);
void test_two_in_three_out_params_functions(void);
void test_three_in_three_out_params_functions(void);

void test_one_table_in_no_out_params_functions(void);
void test_no_in_one_table_out_params_functions(void);
void test_one_table_in_one_out_params_functions(void);
void test_one_in_one_table_out_params_functions(void);
void test_one_table_in_one_table_out_params_functions(void);
void test_two_tables_in_one_table_out_params_functions(void);
void test_one_table_in_two_tables_out_params_functions(void);
void test_two_tables_in_two_tables_out_params_functions(void);

/* ------------------------ Main ------------------------------ */

int main(void)
{
    printf("Starting testing...\r\n");

    printf("Testing functions with no parameters...\r\n");
    test_no_params_functions();
    printf("Testing functions with no parameters ended succesfully.\r\n");

    printf("----------------------------------------------------------------------\r\n");
    
    printf("Proceeding with testing functions with only in parameters...\r\n");
    test_one_in_no_out_params_functions();
    printf("Testing functions with only in parameters ended succesfully.\r\n");

    printf("----------------------------------------------------------------------\r\n");
    
    printf("Proceeding with testing functions with only out parameters...\r\n");
    test_no_in_one_out_params_functions();
    printf("Testing functions with only out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");
    
    printf("Proceeding with testing functions with one in and one out parameter...\r\n");
    test_one_in_one_out_params_functions();
    printf("Testing functions with one in and one out parameter ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");
    
    printf("Proceeding with testing functions with one in and two out parameters...\r\n");
    test_one_in_two_out_params_functions();
    printf("Testing functions with one in and two out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with two in and two out parameters...\r\n");
    test_two_in_two_out_params_functions();
    printf("Testing functions with two in and two out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with two in and three out parameters...\r\n");
    test_two_in_three_out_params_functions();
    printf("Testing functions with two in and three out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with three in and three out parameters...\r\n");
    test_three_in_three_out_params_functions();
    printf("Testing functions with three in and three out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");
   
    printf("Proceeding with testing functions with one table in and no out parameters...\r\n");
    test_one_table_in_no_out_params_functions();
    printf("Testing functions with one table in and no out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with no in and one table out parameters...\r\n");
    test_no_in_one_table_out_params_functions();
    printf("Testing functions with no in and one table out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with one table in and one out parameters...\r\n");
    test_one_table_in_one_out_params_functions();
    printf("Testing functions with one table in and one out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with one in and one table out parameters...\r\n");
    test_one_in_one_table_out_params_functions();
    printf("Testing functions with one in and one table out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with one table in and one table out parameters...\r\n");
    test_one_table_in_one_table_out_params_functions();
    printf("Testing functions with one table in and one table out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with two tables in and one table out parameters...\r\n");
    test_two_tables_in_one_table_out_params_functions();
    printf("Testing functions with two tables in and one table out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with one table in and two tables out parameters...\r\n");
    test_one_table_in_two_tables_out_params_functions();
    printf("Testing functions with one table in and two tables out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Proceeding with testing functions with two tables in and two tables out parameters...\r\n");
    test_two_tables_in_two_tables_out_params_functions();
    printf("Testing functions with two tables in and two tables out parameters ended succesfully.\r\n");
    
    printf("----------------------------------------------------------------------\r\n");

    printf("Testing finished, all tests passed.\r\n");
}

/* ------------------------ Testing functions ------------------------------ */

void test_no_params_functions(void)
{
    printf("Printing empty line:\r\n");
    no_params_no_return_function();
    assert(no_params_int_return_function() == -1);
    assert(no_params_unsigned_int_return_function() == 10);
    assert(no_params_float_return_function() == 1.2f);
    assert(no_params_double_return_function() == 0.5);
    assert(no_params_bool_return_function() == true);
}

/* -------------------------------------------------------------------------- */

void test_one_in_no_out_params_functions(void)
{
    printf("Printing number 10:\r\n");
    one_in_param_no_return_function(10);
    assert(one_in_param_int_return_function(4) == -4);
    assert(one_in_param_unsigned_int_return_function(9) == 90);
    assert(one_in_param_float_return_function(6) == 7.2f);
    assert(one_in_param_double_return_function(8) == 4.0);
    assert(one_in_param_bool_return_function(10) == false);
    assert(one_in_param_bool_return_function(20) == true);
}

/* -------------------------------------------------------------------------- */

void test_no_in_one_out_params_functions(void)
{
    printf("Printing number 5:\r\n");
    int out_param = 5;
    one_out_param_no_return_function(&out_param);
    assert(out_param == 10);
    out_param = 0;
    assert(one_out_param_int_return_function(&out_param) == -1);
    assert(out_param == 10);
    out_param = 0;
    assert(one_out_param_unsigned_int_return_function(&out_param) == 10);
    assert(out_param == 10);
    out_param = 0;
    assert(one_out_param_float_return_function(&out_param) == 1.2f);
    assert(out_param == 10);
    out_param = 0;
    assert(one_out_param_double_return_function(&out_param) == 0.5);
    assert(out_param == 10);
    out_param = 0;
    assert(one_out_param_bool_return_function(&out_param) == true);
    assert(out_param == 10);
}

/* -------------------------------------------------------------------------- */

void test_one_in_one_out_params_functions(void)
{
    printf("Printing numbers 5 and 4.5:\r\n");
    double out_param2 = 4.5;
    one_in_one_out_param_no_return_function(5, &out_param2);
    assert(out_param2 == 7.5);
    out_param2 = 0.0;
    assert(one_in_one_out_param_int_return_function(5, &out_param2) == -5);
    assert(out_param2 == 7.5);
    out_param2 = 0.0;
    assert(one_in_one_out_param_unsigned_int_return_function(5, &out_param2) == 50);
    assert(out_param2 == 7.5);
    out_param2 = 0;
    assert(one_in_one_out_param_float_return_function(4, &out_param2) == 4.8f);
    assert(out_param2 == 6);
    out_param2 = 0;
    assert(one_in_one_out_param_double_return_function(10, &out_param2) == 5);
    assert(out_param2 == 15);
    out_param2 = 0;
    assert(one_in_one_out_param_bool_return_function(5, &out_param2) == false);
    assert(out_param2 == 7.5);
    out_param2 = 0;
    assert(one_in_one_out_param_bool_return_function(20, &out_param2) == true);
    assert(out_param2 == 30);
}

/* -------------------------------------------------------------------------- */

void test_one_in_two_out_params_functions(void)
{
    double out_param2 = 30;
    float out_param3 = 0.0;
    printf("Printing numbers 5, 30 and 0:\r\n");
    one_in_two_out_params_no_return_function(5, &out_param2, &out_param3);
    assert(out_param2 == 50);
    assert(out_param3 == 0.5);
    out_param2 = 0.0;
    out_param3 = 0.0;
    
    assert(one_in_two_out_params_int_return_function(5, &out_param2, &out_param3) == -5);
    assert(out_param2 == 50);
    assert(out_param3 == 0.5);
    out_param2 = 0.0;
    out_param3 = 0.0;
    
    assert(one_in_two_out_params_unsigned_int_return_function(4, &out_param2, &out_param3) == 40);
    assert(out_param2 == 40);
    assert(out_param3 == 0.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(one_in_two_out_params_float_return_function(4, &out_param2, &out_param3) == 4.8f);
    assert(out_param2 == 40);
    assert(out_param3 == 0.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(one_in_two_out_params_double_return_function(4, &out_param2, &out_param3) == 2);
    assert(out_param2 == 40);
    assert(out_param3 == 0.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(one_in_two_out_params_bool_return_function(4, &out_param2, &out_param3) == false);
    assert(out_param2 == 40);
    assert(out_param3 == 0.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(one_in_two_out_params_bool_return_function(11, &out_param2, &out_param3) == true);
    assert(out_param2 == 110);
    assert(out_param3 == 1.1f);
    out_param2 = 0.0;
}

/* -------------------------------------------------------------------------- */

void test_two_in_two_out_params_functions(void)
{
    double out_param2 = 0;
    float out_param3 = 10;
    printf("Printing numbers 5, 50, 0 and 10:\r\n");
    two_in_two_out_params_no_return_function(5, '2', &out_param2, &out_param3);
    assert(out_param2 == 100);
    assert(out_param3 == 50.5f);
    out_param2 = 0.0;
    out_param3 = 0.0;
    
    assert(two_in_two_out_params_int_return_function(5, ' ', &out_param2, &out_param3) == -37);
    assert(out_param2 == 82);
    assert(out_param3 == 32.5f);
    out_param2 = 0.0;
    out_param3 = 0.0;
    
    assert(two_in_two_out_params_unsigned_int_return_function(4, ' ', &out_param2, &out_param3) == 360);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(two_in_two_out_params_float_return_function(4, ' ', &out_param2, &out_param3) == 43.2f);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(two_in_two_out_params_double_return_function(4, ' ', &out_param2, &out_param3) == 18);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(two_in_two_out_params_bool_return_function(4, ' ', &out_param2, &out_param3) == false);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    out_param2 = 0.0;
    out_param3 = 0.0;

    assert(two_in_two_out_params_bool_return_function(11, ' ', &out_param2, &out_param3) == true);
    assert(out_param2 == 142);
    assert(out_param3 == 33.1f);
    out_param2 = 0.0;
    out_param3 = 0.0;
    
    assert(two_in_two_out_params_bool_return_function(4, 'p', &out_param2, &out_param3) == true);
    assert(out_param2 == 152);
    assert(out_param3 == 112.4f);
    out_param2 = 0.0;
}

/* -------------------------------------------------------------------------- */

void test_two_in_three_out_params_functions(void)
{
    double out_param2 = 0;
    float out_param3 = 10.5;
    unsigned int out_param4 = 25;
    printf("Printing numbers 5, 50, 0, 10.5 and 25:\r\n");
    out_param3 = 10.5f;
    two_in_three_out_params_no_return_function(5, '2', &out_param2, &out_param3, &out_param4);
    assert(out_param2 == 100);
    assert(out_param3 == 50.5f);
    assert(out_param4 == 52);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(two_in_three_out_params_int_return_function(4, ' ', &out_param2, &out_param3, &out_param4) == -36);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;
    
    assert(two_in_three_out_params_unsigned_int_return_function(4, ' ', &out_param2, &out_param3, &out_param4) == 360);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(two_in_three_out_params_float_return_function(4, ' ', &out_param2, &out_param3, &out_param4) == 43.2f);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(two_in_three_out_params_double_return_function(4, ' ', &out_param2, &out_param3, &out_param4) == 18);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(two_in_three_out_params_bool_return_function(4, ' ', &out_param2, &out_param3, &out_param4) == false);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(two_in_three_out_params_bool_return_function(11, ' ', &out_param2, &out_param3, &out_param4) == true);
    assert(out_param2 == 142);
    assert(out_param3 == 33.1f);
    assert(out_param4 == 37);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;
    
    assert(two_in_three_out_params_bool_return_function(4, 'p', &out_param2, &out_param3, &out_param4) == true);
    assert(out_param2 == 152);
    assert(out_param3 == 112.4f);
    assert(out_param4 == 114);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;
}

/* -------------------------------------------------------------------------- */

void test_three_in_three_out_params_functions(void)
{
    double out_param2 = 12.2;
    float out_param3 = 10.5f;
    unsigned int out_param4 = 25;
    printf("Printing numbers 5, 2, 1, 12.2, 10.5 and 25:\r\n");
    three_in_three_out_params_no_return_function(5, '2', true, &out_param2, &out_param3, &out_param4);
    assert(out_param2 == 100);
    assert(out_param3 == 50.5f);
    assert(out_param4 == 52);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;
    
    printf("Printing numbers 5, 2, 0, 12.2, 10.5 and 25:\r\n");
    out_param2 = 12.2;
    out_param3 = 10.5f;
    out_param4 = 25;
    three_in_three_out_params_no_return_function(5, '2', false, &out_param2, &out_param3, &out_param4);
    assert(out_param2 == 55);
    assert(out_param3 == 55);
    assert(out_param4 == 55);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_int_return_function(4, ' ', true, &out_param2, &out_param3, &out_param4) == -36);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_int_return_function(4, ' ', false, &out_param2, &out_param3, &out_param4) == 36);
    assert(out_param2 == 36);
    assert(out_param3 == 36);
    assert(out_param4 == 36);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;
    
    assert(three_in_three_out_params_unsigned_int_return_function(4, ' ', true, &out_param2, &out_param3, &out_param4) == 360);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_unsigned_int_return_function(4, ' ', false, &out_param2, &out_param3, &out_param4) == 36);
    assert(out_param2 == 36);
    assert(out_param3 == 36);
    assert(out_param4 == 36);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_float_return_function(4, ' ', true, &out_param2, &out_param3, &out_param4) == 43.2f);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_float_return_function(4, ' ', false, &out_param2, &out_param3, &out_param4) == 36);
    assert(out_param2 == 36);
    assert(out_param3 == 36);
    assert(out_param4 == 36);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_double_return_function(4, ' ', true, &out_param2, &out_param3, &out_param4) == 18);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_double_return_function(4, ' ', false, &out_param2, &out_param3, &out_param4) == 36);
    assert(out_param2 == 36);
    assert(out_param3 == 36);
    assert(out_param4 == 36);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_bool_return_function(4, ' ', true, &out_param2, &out_param3, &out_param4) == false);
    assert(out_param2 == 72);
    assert(out_param3 == 32.4f);
    assert(out_param4 == 34);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;

    assert(three_in_three_out_params_bool_return_function(11, ' ', false, &out_param2, &out_param3, &out_param4) == true);
    assert(out_param2 == 43);
    assert(out_param3 == 43);
    assert(out_param4 == 43);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;
    
    assert(three_in_three_out_params_bool_return_function(-4, 'p', true, &out_param2, &out_param3, &out_param4) == true);
    assert(out_param2 == 72);
    assert(out_param3 == 111.6f);
    assert(out_param4 == 114);
    out_param2 = 0.0;
    out_param3 = 0.0;
    out_param4 = 0;
}

/* -------------------------------------------------------------------------- */

void test_one_table_in_no_out_params_functions(void)
{
    double table[10];

    for (int i=0;i<10;i++)
    {
        table[i] = -15.35;
    }

    printf("Printing 10 numbers in separete lines equal to: -15.35:\r\n");
    one_table_in_no_out_params_no_return_function(table, 10);

    assert(one_table_in_no_out_params_int_return_function(table, 10) == -153);
    assert(one_table_in_no_out_params_unsigned_int_return_function(table, 10) == 153);
    assert(one_table_in_no_out_params_float_return_function(table, 5) == -76.75f);
    printf("%f\r\n", one_table_in_no_out_params_double_return_function(table, 10));
    assert(one_table_in_no_out_params_double_return_function(table, 10) == -153.5);
    assert(one_table_in_no_out_params_bool_return_function(table, 10) == false);
    assert(one_table_in_no_out_params_bool_return_function(table, 3) == true);
}

/* -------------------------------------------------------------------------- */

void test_no_in_one_table_out_params_functions(void)
{
    double table[10];

    no_in_one_table_out_params_no_return_function(table, 10);

    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10);
        table[i] = 0.0;
    }

    assert(no_in_one_table_out_params_int_return_function(table, 10) == -100);
    
    for (int i=0;i<10;i++)
    {
        assert(table[i] == -10);
        table[i] = 0.0;
    }

    assert(one_table_in_no_out_params_unsigned_int_return_function(table, 10) == 100);
    
    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10);
        table[i] = 0.0;
    }

    assert(one_table_in_no_out_params_float_return_function(table, 3) == 30.6f);

    for (int i=0;i<3;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }
    assert(table[3] == 0.0);

    assert(one_table_in_no_out_params_double_return_function(table, 10) == 102);

    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }

    assert(one_table_in_no_out_params_bool_return_function(table, 10) == false);

    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }

    assert(one_table_in_no_out_params_bool_return_function(table, 3) == true);
    
    for (int i=0;i<3;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }

    assert(table[3] == 0.0);
}

/* -------------------------------------------------------------------------- */

void test_one_table_in_one_out_params_functions(void)
{
    double table[10];
    float param_out = 0.0;

    for (int i=0;i<10;i++)
    {
        table[i] = 10.2;
    }

    one_table_in_one_out_param_no_return_function(table, 10, &param_out);
    assert(param_out == 102);
    param_out = 0;

    assert(one_table_in_one_out_param_int_return_function(table, 3, &param_out) == 30);
    assert(param_out == 30);
    param_out = 0.0;

    assert(one_table_in_one_out_param_unsigned_int_return_function(table, 10, &param_out) == 102);
    assert(param_out == 102);
    param_out = 0.0;

    assert(one_table_in_one_out_param_float_return_function(table, 3, &param_out) == 30.6f);
    assert(param_out == 30.6);
    param_out = 0.0;

    assert(one_table_in_one_out_param_double_return_function(table, 10, &param_out) == 102);
    assert(param_out == 102);
    param_out = 0.0;

    assert(one_table_in_one_out_param_bool_return_function(table, 3, &param_out) == false);
    assert(param_out == 30.6);
    param_out = 0.0;

    assert(one_table_in_one_out_param_bool_return_function(table, 10, &param_out) == true);
    assert(param_out == 102);
    param_out = 0.0;
}

/* -------------------------------------------------------------------------- */

void test_one_in_one_table_out_params_functions(void)
{
    double table[10];

    one_param_in_one_table_out_no_return_function(10.2, table, 10);

    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }

    assert(one_param_in_one_table_out_params_int_return_function(10.2, table, 10) == -102);
    
    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }

    assert(one_param_in_one_table_out_unsigned_int_return_function(10.25, table, 10) == 102);
    
    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10.25);
        table[i] = 0.0;
    }

    assert(one_param_in_one_table_out_float_return_function(10.2, table, 4) == 40.8f);
    
    for (int i=0;i<4;i++)
    {
        assert(table[i] == 10.25);
        table[i] = 0.0;
    }
    assert(table[4] == 0.0);

    assert(one_param_in_one_table_out_double_return_function(-10.2, table, 10) == -102);

    for (int i=0;i<10;i++)
    {
        assert(table[i] == -10.2);
        table[i] = 0.0;
    }

    assert(one_param_in_one_table_out_bool_return_function(10.2, table, 10) == false);
    
    for (int i=0;i<10;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }

    assert(one_param_in_one_table_out_bool_return_function(10.2, table, 4) == true);

    for (int i=0;i<4;i++)
    {
        assert(table[i] == 10.2);
        table[i] = 0.0;
    }
    assert(table[4] == 0.0);

}

/* -------------------------------------------------------------------------- */

void test_one_table_in_one_table_out_params_functions(void)
{
    double table_in[10];
    int table_out[10];

    for (int i=0;i<10;i++)
    {
        table_in[i] = 10.3;
    }

    one_table_in_one_table_out_params_no_return_function(table_in, 10, table_out, 10);

    for (int i=0;i<10;i++)
    {
        assert(table_out[i] == 10);
        table_out[i] = 0.0;
    }

    assert(one_table_in_one_table_out_params_int_return_function(table_in, 10, table_out, 5) == 50);

    for (int i=0;i<5;i++)
    {
        assert(table_out[i] == 10);
        table_out[i] = 0.0;
    }
    assert(table_out[5] == 0.0);

    assert(one_table_in_one_table_out_params_unsigned_int_return_function(table_in, 10, table_out, 10) == 100);

    for (int i=0;i<10;i++)
    {
        assert(table_out[i] == 10);
        table_out[i] = 0.0;
    }

    assert(one_table_in_one_table_out_params_float_return_function(table_in, 5, table_out, 10) == 50);
    
    for (int i=0;i<5;i++)
    {
        assert(table_out[i] == 10);
        table_out[i] = 0.0;
    }
    assert(table_out[5] == 0.0);

    assert(one_table_in_one_table_out_params_double_return_function(table_in, 10, table_out, 10) == 100);
    
    for (int i=0;i<10;i++)
    {
        assert(table_out[i] == 10);
        table_out[i] = 0.0;
    }
    
    assert(one_table_in_one_table_out_params_bool_return_function(table_in, 10, table_out, 10) == false);
    
    for (int i=0;i<10;i++)
    {
        assert(table_out[i] == 10);
        table_out[i] = 0.0;
    }
    
    assert(one_table_in_one_table_out_params_bool_return_function(table_in, 5, table_out, 10) == true);
    
    for (int i=0;i<5;i++)
    {
        assert(table_out[i] == 10);
        table_out[i] = 0.0;
    }
    assert(table_out[5] == 0.0);
}

/* -------------------------------------------------------------------------- */

void test_two_tables_in_one_table_out_params_functions(void)
{
    float table_in_one[10];
    int table_in_two[10];
    double table_out[10];

    for (int i=0;i<10;i++)
    {
        table_in_one[i] = 10.3;
        table_in_two[i] = 3;
        table_out[i] = 0.0;
    }

    two_tables_in_one_table_out_params_no_return_function(table_in_one, 10, table_in_two, 10, table_out, 10);

    for (int i=0;i<10;i++)
    {
        assert(table_out[i] == 13.3);
        table_out[i] = 0.0;
    }

    assert(two_tables_in_one_table_out_params_int_return_function(table_in_one, 8, table_in_two, 10, table_out, 10) == 10);

    for (int i=0;i<8;i++)
    {
        assert(table_out[i] == 13.3);
        table_out[i] = 0.0;
    }

    assert(table_out[8] == 3);
    assert(table_out[9] == 3);
    table_out[8] = 0.0;
    table_out[9] = 0.0;

    assert(two_tables_in_one_table_out_params_unsigned_int_return_function(table_in_one, 10, table_in_two, 10, table_out, 8) == 8);

    for (int i=0;i<8;i++)
    {
        assert(table_out[i] == 13.3);
        table_out[i] = 0.0;
    }
    assert(table_out[8] == 0);

    assert(two_tables_in_one_table_out_params_float_return_function(table_in_one, 8, table_in_two, 8, table_out, 10) == 106.4f);

    for (int i=0;i<8;i++)
    {
        assert(table_out[i] == 13.3);
        table_out[i] = 0.0;
    }
    assert(table_out[8] == 0);

    assert(two_tables_in_one_table_out_params_double_return_function(table_in_one, 10, table_in_two, 10, table_out, 10) == 133);
    
    for (int i=0;i<10;i++)
    {
        assert(table_out[i] == 13.3);
        table_out[i] = 0.0;
    }

    assert(two_tables_in_one_table_out_params_bool_return_function(table_in_one, 10, table_in_two, 10, table_out, 5) == false);
    
    for (int i=0;i<5;i++)
    {
        assert(table_out[i] == 13.3);
        table_out[i] = 0.0;
    }
    assert(table_out[5] == 0);

    assert(two_tables_in_one_table_out_params_bool_return_function(table_in_one, 10, table_in_two, 10, table_out, 10) == true);
    
    for (int i=0;i<10;i++)
    {
        assert(table_out[i] == 13.3);
        table_out[i] = 0.0;
    }   
}

/* -------------------------------------------------------------------------- */

void test_one_table_in_two_tables_out_params_functions(void)
{
    float table_in[10];
    double table_out_one[10];
    int table_out_two[10];

    for (int i=0;i<10;i++)
    {
        table_in[i] = 10.3;
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }

    one_table_in_two_tables_out_params_no_return_function(table_in, 10, table_out_one, 10, table_out_two, 10);

    for (int i=0;i<10;i++)
    {
        assert(table_out_one[i] == 10.3);
        assert(table_out_two[i] == 10);
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }

    assert(one_table_in_two_tables_out_params_int_return_function(table_in, 8, table_out_one, 10, table_out_two, 10) == 8);

    for (int i=0;i<8;i++)
    {
        assert(table_out_one[i] == 10.3);
        assert(table_out_two[i] == 10);
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }
    assert(table_out_one[8] == 0.0);
    assert(table_out_two[8] == 0);

    assert(one_table_in_two_tables_out_params_unsigned_int_return_function(table_in, 10, table_out_one, 10, table_out_two, 9) == 10);
    
    for (int i=0;i<9;i++)
    {
        assert(table_out_one[i] == 10.3);
        assert(table_out_two[i] == 10);
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }
    assert(table_out_one[9] == 10.3);
    assert(table_out_two[9] == 0);
    table_out_one[9] = 0.0;

    assert(one_table_in_two_tables_out_params_float_return_function(table_in, 10, table_out_one, 10, table_out_two, 10) == 103);

    for (int i=0;i<10;i++)
    {
        assert(table_out_one[i] == 10.3);
        assert(table_out_two[i] == 10);
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }

    assert(one_table_in_two_tables_out_params_double_return_function(table_in, 8, table_out_one, 10, table_out_two, 10) == 82.4);

    for (int i=0;i<8;i++)
    {
        assert(table_out_one[i] == 10.3);
        assert(table_out_two[i] == 10);
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }

    assert(one_table_in_two_tables_out_params_bool_return_function(table_in, 8, table_out_one, 10, table_out_two, 10) == false);

    for (int i=0;i<8;i++)
    {
        assert(table_out_one[i] == 10.3);
        assert(table_out_two[i] == 10);
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }
    assert(table_out_one[8] == 0.0);
    assert(table_out_two[8] == 0);

    assert(one_table_in_two_tables_out_params_bool_return_function(table_in, 10, table_out_one, 10, table_out_two, 10) == true);

    for (int i=0;i<10;i++)
    {
        assert(table_out_one[i] == 10.3);
        assert(table_out_two[i] == 10);
        table_out_one[i] = 0.0;
        table_out_two[i] = 0;
    }

}

/* -------------------------------------------------------------------------- */

void test_two_tables_in_two_tables_out_params_functions(void)
{
    float table_in_one[10];
    int table_in_two[10];
    double table_out_one[10];
    char table_out_two[10];

    for (int i=0;i<10;i++)
    {
        table_in_one[i] = 10.3;
        table_in_two[i] = 3;
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    two_tables_in_two_tables_out_params_no_return_function(table_in_one, 8, table_in_two, 10, table_out_one, 10, table_out_two, 10);

    assert(strcmp(table_out_two, "Hello Wor") == 0);

    for (int i=0;i<10;i++)
    {
        assert(table_out_one[i] == 13.3);
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    assert(two_tables_in_two_tables_out_params_int_return_function(table_in_one, 8, table_in_two, 10, table_out_one, 10, table_out_two, 8) == 10);

    assert(strcmp(table_out_two, "Hello W") == 0);

    for (int i=0;i<10;i++)
    {
        if (i < 8){
            assert(table_out_one[i] == 13.3);
        }
        else
        {
            assert(table_out_one[i] == 3);
        }
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    assert(two_tables_in_two_tables_out_params_unsigned_int_return_function(table_in_one, 10, table_in_two, 10, table_out_one, 8, table_out_two, 10) == 8);

    assert(strcmp(table_out_two, "Hello Wor") == 0);

    for (int i=0;i<8;i++)
    {
        assert(table_out_one[i] == 13.3);
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    assert(table_out_one[8] == 0);
    assert(table_out_one[9] == 0);
    table_out_two[8] = 0;
    table_out_two[9] = 0;

    assert(two_tables_in_two_tables_out_params_float_return_function(table_in_one, 10, table_in_two, 8, table_out_one, 10, table_out_two, 10) == 127);

    assert(strcmp(table_out_two, "Hello Wor") == 0);

    for (int i=0;i<10;i++)
    {
        if (i < 8){
            assert(table_out_one[i] == 13.3);
        }
        else
        {
            assert(table_out_one[i] == 10.3);
        }
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    assert(two_tables_in_two_tables_out_params_double_return_function(table_in_one, 10, table_in_two, 10, table_out_one, 10, table_out_two, 6) == 133);

    assert(strcmp(table_out_two, "Hello") == 0);

    for (int i=0;i<10;i++)
    {
        assert(table_out_one[i] == 13.3);
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    assert(two_tables_in_two_tables_out_params_bool_return_function(table_in_one, 10, table_in_two, 10, table_out_one, 10, table_out_two, 10) == true);
    
    assert(strcmp(table_out_two, "Hello Wor") == 0);

    for (int i=0;i<10;i++)
    {
        assert(table_out_one[i] == 13.3);
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    assert(two_tables_in_two_tables_out_params_bool_return_function(table_in_one, 10, table_in_two, 10, table_out_one, 8, table_out_two, 10) == false);
    
    assert(strcmp(table_out_two, "Hello Wor") == 0);

    for (int i=0;i<10;i++)
    {
        assert(table_out_one[i] == 13.3);
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    for (int i=0;i<8;i++)
    {
        assert(table_out_one[i] == 13.3);
        table_out_one[i] = 0;
        table_out_two[i] = 0;
    }

    assert(table_out_one[8] == 0);
    assert(table_out_one[9] == 0);
}

/* -------------------------------------------------------------------------- */

