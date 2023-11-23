cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "openssl1.1.1s_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

get_filename_component(sheTestcode_dir ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(father_dir ${sheTestcode_dir} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode_dir}")
message(STATUS "father_dir's path:${father_dir}")
set(openssl_dir "${father_dir}/libraries/openssl-OpenSSL_1_1_1s")
message(STATUS "openssl1.1.1s_dir ${openssl_dir}")
set(zlib_dir "${father_dir}/libraries/zlib-1.2.8")
message(STATUS "zlib_dir ${zlib_dir}")
set(minizip_dir "${father_dir}/libraries/minizip-ng-3.0.9")
message(STATUS "minizip_dir ${minizip_dir}")


# include
include_directories(
        ${openssl_dir}/include
        ${zlib_dir}/include
        ${minizip_dir}/include
)
# lib
link_directories(
        ${openssl_dir}/lib
        ${zlib_dir}/lib
        ${minizip_dir}/lib
)

# aux_source_directory(. SOURCE)
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME}
        ${SRC}
)

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        minizip z ssl crypto )
