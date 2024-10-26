cmake_minimum_required(VERSION 3.10)
project(http-server
  LANGUAGES C
  VERSION 0.1
  DESCRIPTION "A simple HTTP server written in C"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${CMAKE_PROJECT_NAME})
target_include_directories(${CMAKE_PROJECT_NAME}
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
)

add_subdirectory("${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/src")
