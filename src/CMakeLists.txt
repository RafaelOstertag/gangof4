set(sources tetris.cxx
            tetrimino.cxx 
            sdl.cxx 
            window.cxx 
            renderer.cxx 
            minorenderer.cxx 
            tetriminorenderer.cxx 
            circulartetriminostock.cxx
            board.cxx
            boardrenderer.cxx
            texture.cxx
            minotexturestore.cxx
            preview.cxx)


add_executable(tetris ${sources})
target_compile_options(tetris PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetris PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetris ${SDL2_LIBRARIES} )
