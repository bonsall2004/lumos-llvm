# @date 26/03/2024
# @developer bonsall2004
# @link https://github.com/bonsall2004

cmake_minimum_required(VERSION 3.27)
project(hxc_debug)

set(CMAKE_CXX_STANDARD 11)

set(LIB_NAME hxc_debug)

set(SOURCES
    hxc_debug_config.h
    ../../includes/ExitCodes.h
    )

add_library(${LIB_NAME} ${SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(console)
add_subdirectory(timer)
add_subdirectory(utils)

target_link_libraries(${LIB_NAME} PRIVATE console_lib timer_lib utils_lib)
