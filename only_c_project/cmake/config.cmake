
########################################################################################################################
# Global Settings                                                                                                      #
########################################################################################################################

# project name
set(project_name "only_c_project")
# [Release] or [Debug] or [MinSizeRel]
set(compilation_options "Debug")

# src target
set(library_static_name "${project_name}_static")
set(library_dynamic_name "${project_name}_dynamic")
set(generate_lib ON)

# test target
set(test_name "${project_name}_test")
set(generate_test ON)

# exec target
set(exec_name "${project_name}_exec")
set(generate_exec ON)


