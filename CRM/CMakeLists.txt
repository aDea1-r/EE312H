cmake_minimum_required(VERSION 3.15)
project(CRM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CRM
        Invent.h
        main.cpp
        MyString.cpp
        MyString.h
        Project4.cpp)
