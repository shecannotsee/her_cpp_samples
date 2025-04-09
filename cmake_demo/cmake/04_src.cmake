# source src
file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*")
# list(REMOVE_ITEM SRC "${CMAKE_SOURCE_DIR}/src/TaskControl.cpp") # Exclude specific files

# ld lib
set(lib "-pthread"
        "-lgtest"
        "-lgmock")


# exe target
if (project_type STREQUAL "executable")
    add_executable(${project_name} ${SRC})
    add_dependencies(${project_name} googletest)
    target_link_libraries(${project_name} ${lib})
    message(STATUS "This is an executable program")
else()
    message(STATUS "CMakeLists.txt error:target error")
endif ()

# lib target
if (project_type STREQUAL "library")
    add_library(${library_static_name} STATIC ${SRC})
    add_dependencies(${library_static_name} googletest)
    # Rename the generated static library
    set_target_properties(${library_static_name} PROPERTIES OUTPUT_NAME ${project_name})

#    add_library(${library_dynamic_name} SHARED ${SRC})
#    # Rename the generated dynamic library
#    set_target_properties(${library_dynamic_name} PROPERTIES OUTPUT_NAME ${project_name})
else()
    message(STATUS "CMakeLists.txt error:target error")
endif ()
