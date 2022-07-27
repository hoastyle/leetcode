cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(077_combinations)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

add_executable(main main.cpp solution.hpp)
