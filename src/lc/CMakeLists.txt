cmake_minimum_required(VERSION 3.20)
project(lumos-compiler)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    main.cpp
    Lexer/Lexer.cpp
    Lexer/Lexer.hpp
    Lexer/Tokenizer.cpp)

set(COMPILED_HEADERS)
# Delete if no assembly is needed
enable_language(ASM_NASM)
set(ASSEMBLY_SOURCES)

set(BUILD_ARCH "-m64")
set(TARGET_64 ON)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS} ../../deps/thread-master ../../hxc_debug/console/includes ../../hxc_debug/timer/includes)
add_definitions(${LLVM_DEFINITIONS})

add_executable(lc ${SOURCES})

llvm_map_components_to_libnames(llvm_libs Analysis Core ExecutionEngine InstCombine Object OrcJIT RuntimeDyld ScalarOpts Support native)
target_link_libraries(lc PUBLIC ${llvm_libs} console_lib thread_master)