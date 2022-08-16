cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(131_palindrome_partitioning)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

add_executable(${PROJECT_NAME} main.cpp solution.hpp)
