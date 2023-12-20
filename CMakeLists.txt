cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME set)
project(${PROJECT_NAME})

# TODO(Korniakov): not sure if these lines are needed
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Настройки для выходных директорий библиотек и исполняемых файлов
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

# Устанавливаем переменные
set(MP3_LIBRARY "${PROJECT_NAME}")
set(MP3_TESTS "test_${PROJECT_NAME}")
set(MP3_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Включаем директории для поиска заголовочных файлов
include_directories("${MP3_INCLUDE}" gtest)

# Собираем проект
add_subdirectory(src)
add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(test)

# Выводим информацию о конфигурации проекта
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")