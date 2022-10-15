#############################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#############################################################
set(PROJECT_NAME "simple_web_server_test")
get_filename_component(test ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(AllCode ${test} DIRECTORY)
set(3rd "${AllCode}/3rd")
#############################################################
set(Simple-Web-Server "${3rd}/Simple-Web-Server")
set(boost "${3rd}/boost_1_79_0/")
#############################################################
set(CMAKE_CXX_FLAGS "-g")
project(${PROJECT_NAME})
#############################################################
# include
include_directories(
        ${LOCAL_INCLUDE}
        ${boost}/include
        ${Simple-Web-Server}
)
# lib
link_directories(
        ${LOCAL_LIB}
        ${boost}/lib
)
#############################################################
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})
#############################################################
target_link_libraries(${PROJECT_NAME} pthread boost_thread boost_system)
