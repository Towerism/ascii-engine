cmake_minimum_required(VERSION 3.2.3 FATAL_ERROR)

option(ASCII_ENGINE_TESTS "ASCII_ENGINE_TESTS" ON)

include_directories(include/ascii-engine)
add_subdirectory(ascii-engine)

if (${ASCII_ENGINE_TESTS}) 
  list(APPEND CMAKE_CXX_FLAGS "-std=c++14" ${CMAKE_CXX_FLAGS})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
  add_subdirectory(test)
endif()
  

