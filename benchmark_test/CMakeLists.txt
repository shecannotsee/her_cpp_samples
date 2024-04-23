cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "benchmark_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})


set(benchmark "${CMAKE_SOURCE_DIR}/benchmark")

# include
include_directories(${benchmark}/include/)
# lib
link_directories(${benchmark}/lib/)

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
