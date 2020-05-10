cmake_minimum_required(VERSION 3.15)
project(interpreter)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(interpreter
        Input.cpp
        Parse.h Interpret.cpp Interpret.h exptree.cpp exptree.hpp)
