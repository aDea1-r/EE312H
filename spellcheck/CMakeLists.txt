cmake_minimum_required(VERSION 3.15)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_1
        cmake-build-debug/american-english.txt
        cmake-build-debug/bobsledding.txt
        cmake-build-debug/greek-finances.txt
        header.txt
        main.cpp
        proj1_output_duplicates.txt
        proj1_output_noduplicates.txt
        Project1.cpp)
