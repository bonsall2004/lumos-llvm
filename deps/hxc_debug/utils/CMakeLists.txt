# @date 26/03/2024
# @developer bonsall2004 
# @link https://github.com/bonsall2004

set(UTILS_SOURCES
        hxc_utils.cpp
)

add_library(utils_lib ${UTILS_SOURCES})

target_include_directories(utils_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_link_libraries(utils_lib PRIVATE console_lib)