cmake_minimum_required(VERSION 3.16)
project(X_Beginner_Contest_166)

set(CMAKE_CXX_STANDARD 17)

add_executable(A "Y A. A?C/A.cpp")
add_executable(B "Y B. Trick or Treat/B.cpp")
add_executable(C "Y C. Peaks/C.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
    target_compile_definitions("B" PUBLIC DEBUG=1)
    target_compile_definitions("C" PUBLIC DEBUG=1)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions("A" PUBLIC DEBUG=0)
    target_compile_definitions("B" PUBLIC DEBUG=0)
    target_compile_definitions("C" PUBLIC DEBUG=0)
endif()

