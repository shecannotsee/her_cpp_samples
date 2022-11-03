cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "jwt_cpp_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(project_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${project_dir} DIRECTORY)
message(STATUS "project_dir's path:${project_dir}")
message(STATUS "father_dir's path:${father_dir}")
set(jwtcpp "${father_dir}/3rd/jwt-cpp/include")
message(STATUS "jwtcpp's path:${jwtcpp}")
set(openssl "${father_dir}/libraries/openssl-3.0.0")

# include
include_directories(
        ${jwtcpp}
        ${openssl}/include
)
# lib
link_directories(
        ${openssl}/lib
)

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
        )

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        ssl crypto)
