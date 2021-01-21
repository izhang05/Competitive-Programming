cmake_minimum_required(VERSION 3.17)
project(AlgorithmsThread_Tree_Basics_Contest)

set(CMAKE_CXX_STANDARD 17)

add_executable(A "Y A. Circumference of a Tree/A.cpp")
add_executable(B "Y B. Dynamic Diameter/B.cpp")
add_executable(C "Y C. Sloth Naptime/C.cpp")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
    target_compile_definitions("B" PUBLIC DEBUG=1)
    target_compile_definitions("C" PUBLIC DEBUG=1)
endif()
