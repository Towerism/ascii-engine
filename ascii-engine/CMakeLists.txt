add_subdirectory(render)

add_library(ascii_engine stub.cc) # TODO remove stub.cc

set(ASCII_ENGINE_LIBS render)
target_link_libraries(ascii_engine ${ASCII_ENGINE_LIBS})