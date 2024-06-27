# TODO:该cmake无法在ubuntu22.04-gcc11.4-cmake3.28的环境下进行编译，该文件只是用来在ide中进行代码编写
########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "module_test")
add_compile_options(-fmodules-ts)
project(${PROJECT_NAME})

# 目录获取
get_filename_component(sheTestcode_path ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "sheTestcode_path's path:${sheTestcode_path}")

# include
include_directories(${CMAKE_SOURCE_DIR})
# lib
link_directories()

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
file(GLOB_RECURSE MODULE "${CMAKE_SOURCE_DIR}/display.cpp")

add_executable(${PROJECT_NAME} ${SRC} ${MODULE})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread")

########################################################################################################################