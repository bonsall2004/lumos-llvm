# @date 26/03/2024
# @developer bonsall2004 
# @link https://github.com/bonsall2004

set(CONSOLE_SOURCES
        hxc_print.cpp
)

add_library(console_lib ${CONSOLE_SOURCES})

target_include_directories(console_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_link_libraries(console_lib PRIVATE timer_lib)
