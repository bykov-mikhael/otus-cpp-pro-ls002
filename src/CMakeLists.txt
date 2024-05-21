cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hw-001 VERSION ${PROJECT_VESRION})

add_executable(hw-001 main.cpp)

set_target_properties(hw-001 PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(
  hw-001 PRIVATE
  ${CMAKE_SOURCE_DIR}/build # ссылка на config.h.in
  ${CMAKE_SOURCE_DIR}/include/version # ссылка на version
)

# параметры компановщика/линковщика:
# парамтеры библотек должны совпадать с названием в add_library(shared_lib SHARED, add_library(static_lib STATIC
target_link_libraries(hw-001
  version_lib
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(hw-001 PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(hw-001 PRIVATE /W4 /WX)
endif()