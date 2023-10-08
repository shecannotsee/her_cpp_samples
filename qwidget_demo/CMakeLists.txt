cmake_minimum_required(VERSION 3.15)

project(qwidget_demo)

# 添加查找路径，确保这个路径指向正确的Qt安装目录
set(CMAKE_PREFIX_PATH "/home/shecannotsee/desktop/qt_project/install/5.15.2/gcc_64")

# 查找 Qt 包并加载 Qt 的CMake配置
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# 添加可执行文件
add_executable(qwidget_demo main.cpp)

# 链接Qt库，不需要手动添加-pthread，CMake会处理依赖
target_link_libraries(qwidget_demo
        Qt5::Core
        Qt5::Widgets
        )
