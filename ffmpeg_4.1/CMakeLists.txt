########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "ffmpeg_4.1_test")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

# 目录获取
get_filename_component(sheTestcode_path ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "sheTestcode_path's path:${sheTestcode_path}")

set(lib_path "/home/shecannotsee/Desktop/libraries")
set(ffmpeg_include ${lib_path}/ffmpeg_4.1/include)
set(ffmpeg_lib_dir ${lib_path}/ffmpeg_4.1/lib)
set(ffmpeg_lib_list avcodec avfilter avformat avutil avdevice swresample swscale)



# include
include_directories(${ffmpeg_include})
# lib
link_directories(${ffmpeg_lib_dir})

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        -Wl,--start-group
        avcodec avfilter avformat avutil avdevice swresample swscale jpeg
        -Wl,--end-group
        z
        x264
        x265
        lzma
)

########################################################################################################################
