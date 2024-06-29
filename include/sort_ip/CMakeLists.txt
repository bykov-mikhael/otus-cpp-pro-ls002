cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(sort_ip VERSION 0.0.1)

add_library(sort_ip STATIC sort_ip.cpp sort_ip.hpp)

set_target_properties(sort_ip PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(sort_ip
  PRIVATE
  ${CMAKE_SOURCE_DIR}/build
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(sort_ip PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(sort_ip PRIVATE /W4 /WX)
endif()