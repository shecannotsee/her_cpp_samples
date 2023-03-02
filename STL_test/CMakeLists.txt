cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "STL_test")

set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# 修改测试文件
set(temp "temp.cpp")
set(hash "hash_test.cpp")
set(tuple "tuple_test.cpp")
set(list "list_test.cpp")
set(map "map_test.cpp")
set(condition_variable "condition_variable_test.cpp")
set(chrono "chrono_test.cpp")
set(packaged_task "packaged_task_test.cpp")
set(VariableLengthParameterTemplate "VariableLengthParameterTemplate_test.cpp")
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/${temp}")
add_executable(${PROJECT_NAME}
        ${SRC}
        )

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread")
