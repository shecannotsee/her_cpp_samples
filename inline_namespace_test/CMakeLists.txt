# set cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set project information
set(project_name "inline_namespace_test")
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

# link
target_link_libraries(${project_name})
