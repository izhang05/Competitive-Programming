cmake_minimum_required(VERSION 3.17)
project(X_OCT20B___October_Challenge_2020_Division_2)

set(CMAKE_CXX_STANDARD 17)
add_executable(CHEFEZQ "Y 1. CHEFEZQ - Chef and Easy Queries/CHEFEZQ.cpp")
add_executable(CVDRUN "Y 2. CVDRUN - Covid Run/CVDRUN.cpp")
add_executable(POSAND "X 3. POSAND - Positive AND/POSAND.cpp")
add_executable(POSAND_new "X 3. POSAND - Positive AND/POSAND_new.cpp")
add_executable(REPLESX "X 4. REPLESX - Replace for X/REPLESX.cpp")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions("CHEFEZQ" PUBLIC DEBUG=1)
    target_compile_definitions("CVDRUN" PUBLIC DEBUG=1)
    target_compile_definitions("POSAND" PUBLIC DEBUG=1)
    target_compile_definitions("POSAND_new" PUBLIC DEBUG=1)
    target_compile_definitions("REPLESX" PUBLIC DEBUG=1)
endif()

