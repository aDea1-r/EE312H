cmake_minimum_required(VERSION 3.15)
project(set)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(set
        main.cpp
        Project5.cpp
        Set.h)
