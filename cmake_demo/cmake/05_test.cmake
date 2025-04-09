# source file
file(GLOB_RECURSE TEST_SRC "${CMAKE_SOURCE_DIR}/test/*")
# list(REMOVE_ITEM SRC "${CMAKE_SOURCE_DIR}/src/TaskControl.cpp") # Exclude specific files


# test target
add_executable(${test_name} ${TEST_SRC} ${SRC})
add_dependencies(${test_name} googletest)
target_link_libraries(${test_name} ${lib})
