cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "qt5.12_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# 目录获取
get_filename_component(sheTestcode_path ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(sheTestcode_path_father ${sheTestcode_path} DIRECTORY)
message(STATUS "sheTestcode_path_father's path:${sheTestcode_path_father}")

# qt path
set(qt "${sheTestcode_path_father}/libraries/qt-5.12")

# include
include_directories(${qt}/include)
# lib
link_directories(${qt}/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        Qt6Core Qt6Widgets)