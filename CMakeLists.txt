cmake_minimum_required(VERSION 3.2.3 FATAL_ERROR)

option(ASCII_ENGINE_TESTS "ASCII_ENGINE_TESTS" ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++14")

include_directories(include/ascii-engine)
include_directories(.)

add_subdirectory(ascii-engine)

if (${ASCII_ENGINE_TESTS}) 
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
  add_subdirectory(test)
endif()