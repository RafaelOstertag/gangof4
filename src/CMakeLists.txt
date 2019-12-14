set(sources 
            board.cxx
            boardrenderer.cxx
            circulartetriminostock.cxx
            font.cxx
            game.cxx
            help.cxx
            minorenderer.cxx 
            minotexturestore.cxx
            normaltetriminostock.cxx
            pausetext.cxx
            preview.cxx
            randomtetriminostock.cxx
            renderer.cxx 
            scorer.cxx
            sdl.cxx 
            tetrimino.cxx 
            tetriminorenderer.cxx 
            tetris.cxx
            text.cxx
            texturefile.cxx
            texturememory.cxx
            window.cxx
            soundfile.cxx
)


add_executable(tetris ${sources})
target_compile_options(tetris PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetris PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetris ${SDL2_LIBRARIES} )
