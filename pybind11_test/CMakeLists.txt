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

set(api)

pybind11_add_module(double_vector_1D api_1.cpp)
pybind11_add_module(double_vector_2D api_2.cpp)
list(APPEND api double_vector_1D double_vector_2D)

set(CMAKE_INSTALL_PREFIX "./")
install(TARGETS ${api}
        DESTINATION ${PROJECT_NAME}/
)



########################################################################################################################
