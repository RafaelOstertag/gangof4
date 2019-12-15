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
            ${CMAKE_CURRENT_BINARY_DIR}/bluemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/cyanmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/greenmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/orangemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/purplemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/redmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/yellowmino.cxx
)

bmpToCxx(bluemino blueMinoBMP)
bmpToCxx(cyanmino cyanMinoBMP)
bmpToCxx(greenmino greenMinoBMP)
bmpToCxx(orangemino orangeMinoBMP)
bmpToCxx(purplemino purpleMinoBMP)
bmpToCxx(redmino redMinoBMP)
bmpToCxx(yellowmino yellowMinoBMP)

add_executable(tetris ${sources})
target_compile_options(tetris PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetris PRIVATE ${CMAKE_CURRENT_BINARY_DIR} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetris ${SDL2_LIBRARIES} )
