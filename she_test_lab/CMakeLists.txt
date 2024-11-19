# set cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set project information
set(project_name "she_test_lab")
PROJECT(${project_name}
        VERSION 0.0.1
        LANGUAGES CXX
)

# set language standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include template
include_directories()
# lib template
link_directories()

# add source code file
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp"
        "${CMAKE_SOURCE_DIR}/t1_sample.cpp"
        "${CMAKE_SOURCE_DIR}/t2_sample.cpp"
)
add_executable(${project_name} ${SRC})

# link
target_link_libraries(${project_name})
