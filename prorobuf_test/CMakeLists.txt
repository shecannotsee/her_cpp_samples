cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "protobuf_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(sheTestcode_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${sheTestcode_dir} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode_dir}")
message(STATUS "father_dir's path:${father_dir}")
set(protobuf_dir "${father_dir}/libraries/protobuf-3.20.2")
message(STATUS "protobuf_dir ${protobuf_dir}")

# include
include_directories(
        ${protobuf_dir}/include
)
# lib
link_directories(
        ${protobuf_dir}/lib
)

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
file(GLOB_RECURSE protobuf_code "${CMAKE_SOURCE_DIR}/protobuf/*.cc")
add_executable(${PROJECT_NAME}
        ${SRC}
        ${protobuf_code}
        )

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread" protobuf)
