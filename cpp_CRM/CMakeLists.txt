cmake_minimum_required(VERSION 3.15)
project(cpp_CRM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_CRM
        Customer.h
        CustomerDB.cpp
        CustomerDB.h
        main.cpp
        Project7.cpp
        UTString.h)
