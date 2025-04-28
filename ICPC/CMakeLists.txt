cmake_minimum_required(VERSION 3.16)
project(ICPC)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -DLOCAL -O2")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -DLOCAL -std=c++20 -O2")
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -O2 -Wshadow")
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -O2 -Wshadow -fsanitize=address -fsanitize=undefined -fpermissive")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

#file(TOUCH ${CMAKE_CURRENT_BINARY_DIR}/pch.cpp)
#add_library(PCH OBJECT ${CMAKE_BINARY_DIR}/pch.cpp)
#target_precompile_headers(PCH PRIVATE /usr/local/Cellar/gcc/11.2.0/include/c++/11.2.0/x86_64-apple-darwin19/bits/stdc++.h)

file(GLOB_RECURSE FILES RELATIVE ${PROJECT_SOURCE_DIR} CONFIGURE_DEPENDS "*.cpp" "*.cp")

foreach (FILE ${FILES})
    if (NOT ${FILE} MATCHES "cmake-build*")
        get_filename_component(second_dir "${FILE}/../.." ABSOLUTE)
        get_filename_component(third_dir "${FILE}/../../.." ABSOLUTE)
        get_filename_component(second_last_dir "${second_dir}" NAME)
        get_filename_component(third_last_dir "${third_dir}" NAME)
        get_filename_component(FILE_NAME ${FILE} NAME)

        string(REPLACE ".cpp" "" TARGET_NAME "${FILE_NAME}")
        string(REPLACE ".cp" "" TARGET_NAME "${TARGET_NAME}")

        string(REPLACE "/" "-" TARGET_NAME "${TARGET_NAME}")
        string(REPLACE " " "_" TARGET_NAME "${TARGET_NAME}")
        string(REPLACE "." "" TARGET_NAME "${TARGET_NAME}")
        set(TARGET_NAME ${third_last_dir}${second_last_dir}${TARGET_NAME})

        add_executable(${TARGET_NAME} "${FILE}"
                BAPC/2024/H/input.cpp)
        get_filename_component(PARENT_DIR ${FILE}/.. ABSOLUTE)
        message(${TARGET_NAME} " = " ${FILE})
        message(${PARENT_DIR})
        set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PARENT_DIR}" LINKER_LANGUAGE CXX)
#        target_precompile_headers(${TARGET_NAME} REUSE_FROM PCH)
    endif ()
endforeach ()
