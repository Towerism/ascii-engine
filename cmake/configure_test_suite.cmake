cmake_policy(SET CMP0037 OLD)

add_custom_target(test)
macro(run_test test_target)
  add_custom_target(run_${test_target}
    COMMAND ${test_target}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/test")
  add_dependencies(test run_${test_target})
endmacro()

file(WRITE ${CMAKE_BINARY_DIR}/test_sources "")
macro(add_test_sources)
  foreach(src ${ARGN})
    set(src ${src})
    file(APPEND ${CMAKE_BINARY_DIR}/test_sources ${CMAKE_CURRENT_LIST_DIR}/${src} "\n")
  endforeach()
endmacro()

macro(get_test_sources var)
  file(STRINGS ${CMAKE_BINARY_DIR}/test_sources PATHS)
  message("the paths are " ${PATHS})
  foreach(PATH ${PATHS})
    file(RELATIVE_PATH RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${PATH})
    list(APPEND ${var} ${RELATIVE})
  endforeach()
endmacro()