set(DISPLAY_SRCS display.cc
                 terminal_output.cc
                 )
add_library(display ${DISPLAY_SRCS})

set(DISPLAY_LIBS terminal)
target_link_libraries(display ${DISPLAY_LIBS})