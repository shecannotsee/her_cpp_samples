########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "qml_demo")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# turn on moc to qt object
set(CMAKE_AUTOMOC ON)
# 添加查找路径
set(CMAKE_PREFIX_PATH "/home/shecannotsee/desktop/qt_project/install/5.15.2/gcc_64")
# 查找 Qt 包并加载Qt的CMake配置
find_package(Qt5 COMPONENTS Core
                            Quick
                            REQUIRED)

# include
include_directories()
# lib
link_directories()

file(GLOB_RECURSE SRC
        ${CMAKE_SOURCE_DIR}/main.cpp
        ${CMAKE_SOURCE_DIR}/other_class/*.cpp)
add_executable(${PROJECT_NAME} ${SRC})


# 链接Qt库
target_link_libraries(qml_demo "-pthread"
        Qt5::Core
        Qt5::Quick
        )

########################################################################################################################
