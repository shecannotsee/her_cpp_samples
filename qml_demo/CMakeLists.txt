cmake_minimum_required(VERSION 3.15)

project(qml_demo)

# 添加查找路径
set(CMAKE_PREFIX_PATH "/home/shecannotsee/desktop/qt_project/install/5.15.2/gcc_64")
# 查找 Qt 包并加载Qt的CMake配置
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# 添加可执行文件
add_executable(qml_demo
        main.cpp
        )

# 链接Qt库
target_link_libraries(qml_demo
        Qt5::Core
        Qt5::Quick
        )
