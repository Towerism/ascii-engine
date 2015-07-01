find_package(Curses REQUIRED)
if (${CURSES_FOUND})
  include_directories(${CURSES_INCLUDE_DIR})
endif()

set(CURSES_WRAPPER_SRCS curses_wrapper.cc)
add_library(curses_wrapper ${CURSES_WRAPPER_SRCS})

set(CURSES_WRAPPER_LIBS ${CURSES_LIBRARIES})
target_link_libraries(curses_wrapper ${CURSES_WRAPPER_LIBS})