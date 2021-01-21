cmake_minimum_required(VERSION 3.16)
project(X_LTIME84B___May_Lunchtime_2020_Division_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(LOSTWKND "Y 1. LOSTWKND - Lost Weekends/LOSTWKND.cpp")
add_executable(WWALK "Y 2. WWALK - Weird Walk/WWALK.cpp")
add_executable(CONVSTR "Y 3. CONVSTR - Convert the String/CONVSTR.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("LOSTWKND" PUBLIC DEBUG=1)
    target_compile_definitions("WWALK" PUBLIC DEBUG=1)
    target_compile_definitions("CONVSTR" PUBLIC DEBUG=1)
endif()

