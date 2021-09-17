cmake_minimum_required(VERSION 3.20)

project(C_samples)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(C_samples main.c no_params_sample.c only_in_params_sample.c only_out_params_sample.c one_in_one_out_param_sample.c multiple_in_out_params_sample.c tables_params_sample.c)