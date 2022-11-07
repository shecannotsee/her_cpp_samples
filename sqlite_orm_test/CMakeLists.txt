cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "sqlite_orm_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(test ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(AllCode ${test} DIRECTORY)
message(STATUS "AllCode's path:${AllCode}")# /home/shecannotsee/Desktop/AllCode
set(libraries "${AllCode}/libraries")
set(3rd "${AllCode}/3rd")
#
set(sqlite3 "${libraries}/sqlite3")
set(sqlite_orm "${3rd}/sqlite_orm/include")

# include
include_directories(
        ${sqlite_orm}
        ${sqlite3/include}
)
# lib
link_directories(
        ${sqlite3/lib}
)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} sqlite3 "-pthread")