cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "cmake_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# 一种从外部获取源码编译成库的支持，cmake最低支持版本为3.14
include(FetchContent)
# 另一种从源码直接编译的支持，需要cmake的最低版本是3.11
include(ExternalProject)

ExternalProject_Add(
        glog
        # 指定源码
        SOURCE_DIR "${CMAKE_SOURCE_DIR}/third_party/glog"
        # 指定cmake的安装目录
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/glog-install
)

# 将安装后的glog引入到项目中来
include_directories(${CMAKE_SOURCE_DIR}/glog-install/include)

link_directories(${CMAKE_SOURCE_DIR}/glog-install/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")

add_executable(${PROJECT_NAME} ${SRC})

# 指定cmake_test依赖于glog
add_dependencies(${PROJECT_NAME} glog)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/glog-install/lib/libglog.so)
