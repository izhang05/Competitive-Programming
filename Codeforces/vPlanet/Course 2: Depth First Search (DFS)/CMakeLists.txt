cmake_minimum_required(VERSION 3.16)
project(Course_2__Depth_First_Search__DFS_)

set(CMAKE_CXX_STANDARD 17)

add_executable(A "Y A. Rumor/A.cpp")
add_executable(B "X B. Love Rescue/B.cpp")
add_executable(C "X C. Sleepy Game/C.cpp")
add_executable(G "Y G. Journey/G.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
    target_compile_definitions("B" PUBLIC DEBUG=1)
    target_compile_definitions("C" PUBLIC DEBUG=1)
    target_compile_definitions("G" PUBLIC DEBUG=1)
endif()