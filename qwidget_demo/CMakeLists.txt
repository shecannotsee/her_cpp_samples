########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "qwidget_demo")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# 目录获取
get_filename_component(sheTestcode_path ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "sheTestcode_path's path:${sheTestcode_path}")

# 添加查找路径，确保这个路径指向正确的Qt安装目录
set(CMAKE_PREFIX_PATH "/home/shecannotsee/desktop/qt_project/install/5.15.2/gcc_64")
# 查找 Qt 包并加载 Qt 的CMake配置
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# include
include_directories()
# lib
link_directories()


file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        Qt5::Core
        Qt5::Widgets)

########################################################################################################################
