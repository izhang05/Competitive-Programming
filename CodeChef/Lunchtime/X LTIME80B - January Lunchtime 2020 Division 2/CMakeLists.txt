cmake_minimum_required(VERSION 3.16)
project(LTIME80B)

set(CMAKE_CXX_STANDARD 17)

add_executable(STFOOD "Y 1. STFOOD - Chef and Street Food/STFOOD.cpp")
add_executable(BFRIEND "Y 2. BFRIEND - Bob and His Friends/BFRIEND.cpp")
add_executable(POPTUNNL "X 3. POPTUNNL - Under the Tunnels/POPTUNNL.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("STFOOD" PUBLIC DEBUG=1)
    target_compile_definitions("BFRIEND" PUBLIC DEBUG=1)
    target_compile_definitions("POPTUNNL" PUBLIC DEBUG=1)
endif()



