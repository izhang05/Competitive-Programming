cmake_minimum_required(VERSION 3.17)
project(IOI)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(GCC_COVERAGE_COMPILE_FLAGS "-Wshadow -Wall -o -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(traffic "X 2010/Y 6. Traffic/traffic.cpp")
add_executable(cluedo "X 2010/Y 1. Cluedo/cluedo.cpp")
add_executable(memory "X 2010/Y 5. Memory/memory.cpp")
add_executable(supertrees "X 2020/X 2. Connecting Supertrees/supertrees.cpp")
set_target_properties(supertrees PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/X 2020/X 2. Connecting Supertrees")
add_executable(supertrees_grader "X 2020/X 2. Connecting Supertrees/grader.cpp")
set_target_properties(supertrees_grader PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/X 2020/X 2. Connecting Supertrees")
