# @date 26/03/2024
# @developer bonsall2004 
# @link https://github.com/bonsall2004

set(TIMER_SOURCES
        hxc_timer.cpp
)

add_library(timer_lib ${TIMER_SOURCES})

target_include_directories(timer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)