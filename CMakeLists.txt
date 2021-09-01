
cmake_minimum_required(VERSION 3.16.3)

project(sma)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)