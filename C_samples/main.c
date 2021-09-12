#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "no_params_sample.h"
#include "only_in_params_sample.h"
#include "only_out_params_sample.h"
#include "one_in_one_out_param_sample.h"
// #include "multiple_in_out_params_sample.h"
// #include "tables_params_sample.h"

int main(void)
{
    printf("Testing functions with no parameters...\r\n");

    printf("Printing empty line:\r\n");
    no_params_no_return_function();
    assert(no_params_int_return_function() == -1);
    assert(no_params_unsigned_int_return_function() == 10);
    assert(no_params_float_return_function() == 1.2f);
    assert(no_params_double_return_function() == 0.5);
    assert(no_params_bool_return_function() == true);

    printf("Testing functions with no parameters ended succesfully.\r\n");
    
    printf("Proceeding with testing functions with only in parameters...\r\n");
    printf("Printing number 10:\r\n");
    one_in_param_no_return_function(10);
    assert(one_in_param_int_return_function(4) == -4);
    assert(one_in_param_unsigned_int_return_function(9) == 90);
    assert(one_in_param_float_return_function(6) == 7.2f);
    assert(one_in_param_double_return_function(8) == 4.0);
    assert(one_in_param_bool_return_function(10) == false);
    assert(one_in_param_bool_return_function(20) == true);

    printf("Testing functions with only in parameters ended succesfully.\r\n");
    
    printf("Proceeding with testing functions with only out parameters...\r\n");
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

    printf("Testing functions with only out parameters ended succesfully.\r\n");
    
    printf("Proceeding with testing functions with one in and one out parameter...\r\n");
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
    assert(one_in_one_out_param_bool_return_function(5, &out_param2) == true);
    assert(out_param2 == 7.5);
    out_param2 = 0;
    assert(one_in_one_out_param_bool_return_function(20, &out_param2) == false);
    assert(out_param2 == 30);

    printf("Testing functions with one in and one out parameter ended succesfully.\r\n");
    
    printf("Proceeding with testing functions with one in and two out parameters...\r\n");

    //TODO
}
