cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11) # googletest min cpp standard is c++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "benchmark_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

#
get_filename_component(sheTestcode ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode}")
get_filename_component(sheTestcode_f ${sheTestcode} DIRECTORY)
message(STATUS "sheTestcode_f's path:${sheTestcode_f}")

set(benchmark "${sheTestcode_f}/libraries/benchmark-1.7.0")
############################################################

# include
include_directories(
        ${benchmark}/include/
)
# lib
link_directories(
        ${benchmark}/lib/
)

###############################################################

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
        )
#################################################################

# 链接库
target_link_libraries(${PROJECT_NAME}
        "-pthread"
        benchmark
        )
