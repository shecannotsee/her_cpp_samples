cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "boost_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

#
get_filename_component(sheTestcode ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode}")
get_filename_component(sheTestcode_father_dir ${sheTestcode} DIRECTORY)
message(STATUS "sheTestcode_father_dir's path:${sheTestcode_father_dir}")
set(boost "${sheTestcode_father_dir}/libraries/boost-1.79.0")
message(STATUS "testcode's path:${boost}")# /Users/shecannotsee/Desktop/AllCode/testcode



# include
include_directories(${boost}/include)
# lib
link_directories(${boost}/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread")