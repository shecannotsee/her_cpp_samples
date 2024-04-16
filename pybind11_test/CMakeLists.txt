########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "pybind11_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/pybind11")
find_package(pybind11 REQUIRED)

# include
include_directories()
# lib
link_directories()

pybind11_add_module(api_1 api_1.cpp)

########################################################################################################################
