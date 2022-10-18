cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "spdlog_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(project_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${project_dir} DIRECTORY)
message(STATUS "project_dir's path:${project_dir}")
message(STATUS "father_dir's path:${father_dir}")
set(spdlog "${father_dir}/3rd/spdlog/include")

# include
include_directories(${spdlog})
# lib
link_directories()

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
        )

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread")
