cmake_minimum_required(VERSION 3.20)

project(C_samples)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB SRC_FILES "*.c")

add_executable(C_samples ${SRC_FILES})

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(C_samples PRIVATE m)
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")