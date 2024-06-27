cmake_minimum_required(VERSION 3.28)

project(modules-example)

set(CMAKE_CXX_STANDARD 20)

add_executable(demo)
target_sources(demo
        PUBLIC
        main.cpp
)
target_sources(demo
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        cpp20_test.cppm
)