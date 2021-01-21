cmake_minimum_required(VERSION 3.16)
project(X_LTIME85___June_Lunchtime_2020)

set(CMAKE_CXX_STANDARD 17)

add_executable(A A/A.cpp)
add_executable(B B/B.cpp)
add_executable(C C/C.cpp)
add_executable(D D/D.cpp)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
    target_compile_definitions("B" PUBLIC DEBUG=1)
    target_compile_definitions("C" PUBLIC DEBUG=1)
    target_compile_definitions("D" PUBLIC DEBUG=1)
endif()
