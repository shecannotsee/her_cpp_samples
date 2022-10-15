#############################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#############################################################
set(PROJECT_NAME "mysql_c_test")
get_filename_component(test ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(AllCode ${test} DIRECTORY)
set(3rd "${AllCode}/3rd")
set(MYSQL "/usr/include/mysql")
#############################################################

#############################################################
set(CMAKE_CXX_FLAGS "-g")
project(${PROJECT_NAME})
#############################################################
# include
include_directories(
        ${LOCAL_INCLUDE}
        ${MYSQL}
)
# lib
link_directories(
        ${LOCAL_LIB}
)
#############################################################
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})
#############################################################
target_link_libraries(${PROJECT_NAME} pthread mysqlclient)
