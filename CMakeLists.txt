cmake_minimum_required(VERSION 3.9)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode main.cpp solutions.h valid_sudoku.cpp three_sum.cpp three_sum_closest.cpp letter_comb.cpp)