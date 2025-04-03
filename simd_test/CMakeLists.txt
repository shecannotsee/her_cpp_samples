# set cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set project information
set(project_name "simd_test")
PROJECT(${project_name})

# set language standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include template
include_directories()
# lib template
link_directories()

# add source code file
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${project_name} ${SRC})
# 自动检测编译器
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # 添加AVX-512编译选项
    target_compile_options(${project_name} PRIVATE -mavx2)
    # 可选：使用-march=native自动优化本地架构
    # target_compile_options(${project_name} PRIVATE -march=native)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # MSVC需要使用不同的选项
    target_compile_options(${project_name} PRIVATE /arch:AVX512)
endif()

# link
target_link_libraries(${project_name})
