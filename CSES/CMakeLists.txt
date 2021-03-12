cmake_minimum_required(VERSION 3.16)
project(CSES)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DLOCAL")
set(GCC_COVERAGE_COMPILE_FLAGS "-Wshadow -Wall -o -D_GLIBCXX_DEBUG -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")


file(GLOB_RECURSE FILES RELATIVE ${PROJECT_SOURCE_DIR} CONFIGURE_DEPENDS "*.cpp")

foreach (FILE ${FILES})
    if (NOT ${FILE} MATCHES "cmake-build*")
        get_filename_component(FILE_NAME ${FILE} NAME)
        string(REPLACE ".cpp" "" TARGET_NAME "${FILE_NAME}")
        string(REPLACE "/" "-" TARGET_NAME "${TARGET_NAME}")
        string(REPLACE " " "_" TARGET_NAME "${TARGET_NAME}")
        string(REPLACE "." "" TARGET_NAME "${TARGET_NAME}")
        add_executable(${TARGET_NAME} "${FILE}")
        get_filename_component(PARENT_DIR ${FILE}/.. ABSOLUTE)
        message(${TARGET_NAME} " = " ${FILE})
        message(${PARENT_DIR})
        set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PARENT_DIR}")
    endif ()
endforeach ()
