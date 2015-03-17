cmake_minimum_required(VERSION 3.1)
project(RecursionProblems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(RecursionProblems ${SOURCE_FILES} recursion.h)