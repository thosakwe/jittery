cmake_minimum_required(VERSION 3.9)
project(jittery)

set(CMAKE_CXX_STANDARD 11)

find_path(ANTLR4_INCLUDE_DIR antlr4-runtime/antlr4-runtime.h)
find_path(LIBJIT_INCLUDE_DIR jit/jit.h)

find_library(ANTLR4 antlr4-runtime)
find_library(LIBJIT jit)

include_directories(${ANTLR4_INCLUDE_DIR}/antlr4-runtime)
include_directories(${LIBJIT_INCLUDE_DIR})
include_directories(include)
add_subdirectory(src)