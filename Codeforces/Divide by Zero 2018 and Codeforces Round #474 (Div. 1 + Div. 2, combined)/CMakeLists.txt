# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 3.16)

project(Divide_by_Zero_2018_and_Codeforces_Round__474__Div__1___Div__2__combined_)

set(CMAKE_CXX_STANDARD 17)


# Add tasks subprojects
include(cmake/utils.cmake)
add_subprojects(${CMAKE_SOURCE_DIR})