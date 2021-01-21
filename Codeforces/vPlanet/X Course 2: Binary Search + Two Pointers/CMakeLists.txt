cmake_minimum_required(VERSION 3.16)
project(X_Course_2__Binary_Search___Two_Pointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(A "Y A. Guess the Number/A.cpp")
add_executable(B "X B. Three-level Laser/B.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
    target_compile_definitions("B" PUBLIC DEBUG=1)
endif()
