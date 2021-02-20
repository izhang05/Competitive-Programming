cmake_minimum_required(VERSION 3.17)
project(CEOI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DLOCAL")
set(GCC_COVERAGE_COMPILE_FLAGS "-Wshadow -Wall -o -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")


add_executable(tower "2010/Day 2/X 3. A Huge Tower/tower.cpp")
set_target_properties(tower PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/2010/Day 2/X 3. A Huge Tower")
add_executable(fence "2020/Day 1/X 1. Fancy Fence/fence.cpp")
set_target_properties(fence PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/2020/Day 1/X 1. Fancy Fence")