# проверка минимальной версии установленного cmake
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# подключение бибилотеки boost::test
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# подключение бибилоитеки gtest
find_package(GTest REQUIRED)

# включение мсходных файлов для компиляции
add_executable(unit_tests btest_version.cpp) # gtests_version.cpp)

# указание стандарта языка С++ для таргета
set_target_properties(unit_tests PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

set_target_properties(unit_tests PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# указание путей для директивы include ...
target_include_directories(unit_tests PRIVATE
  ${CMAKE_SOURCE_DIR}/include/version # ... библиотеки version
  ${CMAKE_SOURCE_DIR}/include/sort_ip # ... библиотеки sort_ip
)

# указание путей бибилиотек для линковщика ...
target_link_libraries(unit_tests
  ${Boost_LIBRARIES} # ... библиотеки boost
  version_lib # ... библиотеки version
  sort_ip # ... библиотеки sort_ip
)

# настройка параметров компиляции в зависимости от целевой платформы
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(unit_tests PRIVATE -g -Wall -Wextra -Werror -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(unit_tests PRIVATE /W4 /WX)
endif()

# добавление тестов google tests
target_link_libraries(unit_tests GTest::gtest GTest::gtest_main)