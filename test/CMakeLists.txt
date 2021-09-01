cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Executable to run all tests
add_executable("${CMAKE_PROJECT_NAME}_tests"
               ${CMAKE_SOURCE_DIR}/src/sma_device.cpp
               sma_device_calculation_test.cpp
               sma_device_read_test.cpp
               sma_device_write_test.cpp)

# Link pthread library to enable std::thread
target_link_libraries("${CMAKE_PROJECT_NAME}_tests" gtest_main)
add_test(NAME "${CMAKE_PROJECT_NAME}_tests" COMMAND "${CMAKE_PROJECT_NAME}_tests")