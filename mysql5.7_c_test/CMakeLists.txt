cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "mysql5.7_c_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(sheTestcode ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${sheTestcode} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode}")#
message(STATUS "father_dir's path:${father_dir}")#

set(mysql "${father_dir}/libraries/mysql")


# include
include_directories(${mysql}/include)
# lib
link_directories(${mysql}/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread" mysqlclient )