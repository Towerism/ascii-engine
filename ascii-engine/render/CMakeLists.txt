set(RENDER_SRCS char_matrix.cc
                line_extractor.cc
                renderable.cc
                matrix_renderer.cc
                )
add_library (render ${RENDER_SRCS})