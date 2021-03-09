cmake_minimum_required(VERSION 3.17)
project(Segment_Tree__part_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DLOCAL")
set(GCC_COVERAGE_COMPILE_FLAGS "-Wshadow -Wall -o -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(A-Segment_with_the_Maximum_Sum "X Step 2/XA. Segment with the Maximum Sum.cpp")
set_target_properties(A-Segment_with_the_Maximum_Sum PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/X Step 2/")