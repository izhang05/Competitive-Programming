cmake_minimum_required(VERSION 3.16)
project(Course_1__Nested_Loops)

set(CMAKE_CXX_STANDARD 17)


add_executable(C "Y C. Crossword solving/C.cpp")
add_executable(D "Y D. Black Square/D.cpp")
add_executable(E "Y E. ACM ICPC/E.cpp")
add_executable(F "Y F. Masha and Bears/F.cpp")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("C" PUBLIC DEBUG=1)
    target_compile_definitions("D" PUBLIC DEBUG=1)
    target_compile_definitions("E" PUBLIC DEBUG=1)
    target_compile_definitions("F" PUBLIC DEBUG=1)
endif()


