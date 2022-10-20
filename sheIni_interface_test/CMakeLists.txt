cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "sheIni_interface_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(test_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${test_dir} DIRECTORY)
message(STATUS "test_dir's path:${test_dir}")
message(STATUS "father_dir's path:${father_dir}")

set(sheIni "${father_dir}/sheIni")

# include
include_directories(
        ${sheIni}/src
)
# lib
link_directories()

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
file(GLOB_RECURSE sheIni_part1 "${sheIni}/src/DataStructure/*.cpp")
file(GLOB_RECURSE sheIni_part2 "${sheIni}/src/Parse/*.cpp")
add_executable(${PROJECT_NAME} ${SRC}
        ${sheIni_part1}
        ${sheIni_part2}
        )

# 链接库
target_link_libraries(${PROJECT_NAME} pthread)
