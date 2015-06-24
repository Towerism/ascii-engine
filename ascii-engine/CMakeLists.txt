add_subdirectory(display)

add_library(ascii_engine stub.cc) # TODO remove stub.cc

set(ASCII_ENGINE_LIBS display)
target_link_libraries(ascii_engine display)