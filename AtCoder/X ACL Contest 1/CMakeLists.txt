cmake_minimum_required(VERSION 3.17)
project(X_ACL_Contest_1)

set(CMAKE_CXX_STANDARD 17)
add_executable(A "X A - Reachable Towns/A.cpp")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("A" PUBLIC DEBUG=1)
endif()