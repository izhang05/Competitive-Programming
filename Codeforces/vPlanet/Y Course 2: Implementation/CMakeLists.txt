cmake_minimum_required(VERSION 3.16)
project(Y_Course_2__Implementation)

set(CMAKE_CXX_STANDARD 17)

add_executable(A "Y A. Two Seals/A.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
endif()