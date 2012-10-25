cmake_minimum_required(VERSION 2.8)
project(quiz3)
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src/main
  ${PROJECT_SOURCE_DIR}/src/test
)
add_subdirectory(${PROJECT_SOURCE_DIR}/gtest-1.6.0)
include_directories(${PROJECT_SOURCE_DIR}/gtest-1.6.0/include)

add_executable(tests 
  src/test/lab4tests.cpp
  src/main/shape.cpp
)
target_link_libraries(tests gtest_main)
