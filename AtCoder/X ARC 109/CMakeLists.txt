cmake_minimum_required(VERSION 3.17)
project(X_ARC_109)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(GCC_COVERAGE_COMPILE_FLAGS "-Wshadow -Wall -o -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
add_executable(a "X A. Hands/a.cpp")
set_target_properties(a PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/X A. Hands")