# message(STATUS "MY_VARIABLE=${CMAKE_SOURCE_DIR}")

# проверка минимальной версии установленного cmake
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.1.${PATCH_VERSION})

# устанавливается имя исполняемого файла
project(hw-002 VERSION ${PROJECT_VESRION})

# подключается папка с главной функцией - main.cpp
add_subdirectory(src)

# подключается статическая бибилотека version
add_subdirectory(include/version)

# подключается тестирование
enable_testing()

# подключается папка с тестами
add_subdirectory(tests)

install(TARGETS hw-002 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(NAME btests COMMAND unit_tests)

add_test(NAME gtests COMMAND unit_tests)