cmake_minimum_required(VERSION 3.11)

include(${CMAKE_SOURCE_DIR}/cmake/00_config.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/01_compilation_options.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/02_build_3rd.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/03_import.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/04_src.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/05_test.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/06_install.cmake)

PROJECT(${project_name}
        VERSION      0.0.1
        LANGUAGES    CXX
        )
