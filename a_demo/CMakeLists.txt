cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "xxxx")
set(LOCAL_INCLUDE "/usr/local/include/")
set(LOCAL_LIB "/usr/local/lib/")
set(BREW "/opt/homebrew/Cellar/")
# protobuf
set(PROTOBUF_INCLUDE "${BREW}/protobuf/3.17.3/include/google/")
set(PROTOBUF_LIB "${BREW}/protobuf/3.17.3/lib/")
# grpc
set(GRPC_INCLUDE "${BREW}/grpc/1.38.0/include/")
set(GRPC_LIB "${BREW}/grpc/1.38.0/lib/")

#
get_filename_component(a_demo ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "a_demo's path:${a_demo}")#/Users/shecannotsee/Desktop/AllCode/testcode/a-demo
get_filename_component(testcode ${a_demo} DIRECTORY)
message(STATUS "testcode's path:${testcode}")# /Users/shecannotsee/Desktop/AllCode/testcode

set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# include
include_directories(
        ${LOCAL_INCLUDE}
        ${PROTOBUF_INCLUDE}
        ${GRPC_INCLUDE}
)
# lib
link_directories(
        ${LOCAL_LIB}
        ${PROTOBUF_LIB}
        ${GRPC_LIB}
)

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*")
file(GLOB_RECURSE FRAMEWORK "${CMAKE_SOURCE_DIR}/src/*")
add_executable(${PROJECT_NAME}
        ${SRC}
        # ${FRAMEWORK}
        ../grpc_test/client/main.cpp
)

# 链接库
target_link_libraries(${PROJECT_NAME} pthread)
