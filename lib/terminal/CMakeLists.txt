find_package(Curses REQUIRED)
if (${CURSES_FOUND})
  include_directories(${CURSES_INCLUDE_DIR})
endif()

set(TERMINAL_SRCS curses_wrapper.cc)
add_library(terminal ${TERMINAL_SRCS})

set(TERMINAL_LIBS ${CURSES_LIBRARIES})
target_link_libraries(terminal ${TERMINAL_LIBS})