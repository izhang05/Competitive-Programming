cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(h h.cpp
        b.cpp
        b_brute.cpp
        bad.cpp
        good.cpp a.cpp
        d.cpp)
#add_executable(a a.cpp)
add_executable(l L.cpp)