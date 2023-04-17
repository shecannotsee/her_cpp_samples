cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "cmake_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# 一种从外部获取源码编译成库的支持，cmake最低支持版本为3.11
include(FetchContent)
# 另一种从源码直接编译的支持
include(ExternalProject)

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/glog-install")
    # 指定cmake_test依赖于glog
    message(STATUS "Need to compile third-party libraries:glog.")
    # 如果库不存在，就编译第三方库
    ExternalProject_Add(
            glog
            # 指定源码
            SOURCE_DIR "${CMAKE_SOURCE_DIR}/third_party/glog"
            # 指定cmake的安装目录
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/glog-install
    )
else()
    message(STATUS "Glog does not need to be compiled again.")
endif()

# 从url拉取第三方库并且进行编译，通过该方式添加的库会出现${CMAKE_BINARY_DIR}目录下
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.12.x
)
FetchContent_MakeAvailable(googletest)


# 将安装后的glog引入到项目中来
include_directories(${CMAKE_SOURCE_DIR}/glog-install/include)

link_directories(${CMAKE_SOURCE_DIR}/glog-install/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")

add_executable(${PROJECT_NAME} ${SRC})

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/glog-install")
    message(STATUS "Add Compilation Dependency")
    add_dependencies(${PROJECT_NAME} glog)
endif()
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/glog-install/lib/libglog.so gtest gmock)

