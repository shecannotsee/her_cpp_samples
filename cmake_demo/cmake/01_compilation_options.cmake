########################################################################################################################
# Global Settings
########################################################################################################################
# project name
set(project_name "cmake_demo")

# [Release] or [Debug] or [MinSizeRel]
set(compilation_options "Debug")

# [library] or [executable]
set(project_type "library")

# target
set(library_static_name "${project_name}_static")
set(library_dynamic_name "${project_name}_dynamic")

# test target
set(test_name "${project_name}_test")

########################################################################################################################
# Compilation Options
########################################################################################################################

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_BUILD_TYPE ${compilation_options})


