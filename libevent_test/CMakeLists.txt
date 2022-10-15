cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "libevent_test")
###################################################
get_filename_component(test ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(AllCode ${test} DIRECTORY)
message(STATUS "AllCode's path:${AllCode}")# /home/shecannotsee/Desktop/AllCode
set(libraries "${AllCode}/libraries")
###################################################
set(libevent "${libraries}/libevent-2.1.12")
###################################################
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})
# include
include_directories(
        ${libevent}/include)
# lib
link_directories(
        ${libevent}/lib
)
###################################################
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
        )
###################################################
# 链接库
target_link_libraries(${PROJECT_NAME} event pthread)
