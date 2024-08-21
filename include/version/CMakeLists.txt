cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(version_lib VERSION 0.0.2)

configure_file(
  version.h.in
  ${CMAKE_SOURCE_DIR}/build/version.h
)

add_library(version_lib STATIC lib.cpp lib.h)

set_target_properties(version_lib PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(version_lib
  PRIVATE
  ${CMAKE_SOURCE_DIR}/build
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(version_lib PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(version_lib PRIVATE /W4 /WX)
endif()