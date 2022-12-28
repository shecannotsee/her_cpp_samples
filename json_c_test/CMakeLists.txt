cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "json_c_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(sheTestcode_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${sheTestcode_dir} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode_dir}")
message(STATUS "father_dir's path:${father_dir}")
set(json-c "${father_dir}/libraries/json-c")
message(STATUS "protobuf_dir ${openssl_dir}")

# include
include_directories(
        ${json-c}/include
)
# lib
link_directories(
        ${json-c}/lib
)

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
        )

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        json-c)
