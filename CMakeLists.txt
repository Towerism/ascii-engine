cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

option(ENABLE_TESTING "Enable tests" OFF)
option(ENABLE_COVERAGE "Enable test coverage analysis (debug, linux builds only)" OFF)

if (ENABLE_COVERAGE AND NOT WIN32 AND NOT APPLE) 
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage") 
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage") 
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
endif() 

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(include/ascii-engine)
include_directories(.)

add_subdirectory(ascii-engine)
add_subdirectory(lib)

if (${ENABLE_TESTING}) 
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
  add_subdirectory(test)
endif()