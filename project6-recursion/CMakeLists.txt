cmake_minimum_required(VERSION 3.15)
project(project6_recursion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project6_recursion
        main.cpp
        MazeParams.h
        Project6.cpp
        Recursion.h)
