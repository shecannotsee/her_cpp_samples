cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "mqtt_lib_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# 目录获取
get_filename_component(sheTestcode ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(sheTestcode_father ${sheTestcode} DIRECTORY)
message(STATUS "sheTestcode_father's path:${sheTestcode_father}")

# 添加mqtt库路径
set(paho.mqtt.c-1.3.10 "${sheTestcode_father}/libraries/paho.mqtt.c-1.3.10")
# 添加mqtt-cpp库路径
set(paho.mqtt.cpp-1.2.0 "${sheTestcode_father}/libraries/paho.mqtt.cpp-1.2.0")

# include
include_directories(
        ${paho.mqtt.c-1.3.10}/include
        ${paho.mqtt.cpp-1.2.0}/include)
# lib
link_directories(
        ${paho.mqtt.c-1.3.10}/lib
        ${paho.mqtt.cpp-1.2.0}/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        paho-mqtt3as paho-mqtt3cs
        paho-mqttpp3)