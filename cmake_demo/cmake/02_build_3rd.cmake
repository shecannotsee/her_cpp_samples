
include(ExternalProject)

function(compiling_3rd 3rd_name)
    if (NOT EXISTS "${CMAKE_SOURCE_DIR}/third_party/${3rd_name}-install")
        message(STATUS "Need to compile third-party libraries:${3rd_name}.")
        # compliling
        ExternalProject_Add(
                googletest
                # 指定源码
                SOURCE_DIR "${CMAKE_SOURCE_DIR}/third_party/${3rd_name}"
                # 指定cmake的安装目录
                CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/third_party/${3rd_name}-install
        )
    else()
        message(STATUS "${3rd_name} does not need to be compiled again.")
    endif()
endfunction()

compiling_3rd(googletest)




