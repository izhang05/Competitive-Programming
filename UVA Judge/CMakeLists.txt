cmake_minimum_required(VERSION 3.16)
project(UVA_Judge)

set(CMAKE_CXX_STANDARD 11)

add_executable(maxsum "Y 108 - Maximum Sum/maxsum.cpp")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("maxsum" PUBLIC DEBUG=1)
endif()