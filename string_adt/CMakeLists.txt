cmake_minimum_required(VERSION 3.15)
project(string_adt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(string_adt
        main.cpp
        Project3.cpp
        String.h)
