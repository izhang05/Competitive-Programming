cmake_minimum_required(VERSION 3.16)
project(Course_1__Math)

set(CMAKE_CXX_STANDARD 17)

add_executable(A "Y A. The Eternal Immortality/A.cpp")
add_executable(B "Y B. Classroom Watch/B.cpp")
add_executable(C "Y C. Magic Forest/C.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
    target_compile_definitions("B" PUBLIC DEBUG=1)
    target_compile_definitions("C" PUBLIC DEBUG=1)
endif()


