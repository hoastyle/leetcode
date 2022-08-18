cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(leetcode)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

# TODO: change to for each to add subdirectory automactically
add_subdirectory(017_letter_combinations)
add_subdirectory(039_combination_sum)
add_subdirectory(040_combination_sum2)
add_subdirectory(077_combinations)
add_subdirectory(131_palindrome_partitioning)
add_subdirectory(216_combination_sum)
add_subdirectory(093_restore_ip_addresses)
