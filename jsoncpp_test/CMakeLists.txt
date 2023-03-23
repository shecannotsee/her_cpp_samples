cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "jsoncpp__test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(sheTestcode_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${sheTestcode_dir} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode_dir}")
message(STATUS "father_dir's path:${father_dir}")
set(jsoncpp-1.9.5 "${father_dir}/libraries/jsoncpp-1.9.5")

# include
include_directories(
        ${jsoncpp-1.9.5}/include
)
# lib
link_directories(
        ${jsoncpp-1.9.5}/lib
)

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
        )

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        jsoncpp)
