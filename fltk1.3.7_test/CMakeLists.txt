cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "fltk1.3.7_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# set path
get_filename_component(sheTestcode ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "sheTestcode's path:${sheTestcode}")
get_filename_component(sheTestcode_f ${sheTestcode} DIRECTORY)
message(STATUS "sheTestcode_f's path:${sheTestcode_f}")

set(fltk_dir "${sheTestcode_f}/libraries/fltk-1.3.7")

# include
include_directories(${fltk_dir}/include)
# lib
link_directories(${fltk_dir}/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        fltk "-lX11" dl
)