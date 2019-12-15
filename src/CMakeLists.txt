set(sources 
            ${CMAKE_CURRENT_BINARY_DIR}/bluemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/cyanmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/greenmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/orangemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/purplemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/redmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/yellowmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/collision.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/gameover.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/move.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/rotate.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/rowfull.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/rowfull.cxx
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
            soundfile.cxx
            soundmemory.cxx
            tetrimino.cxx 
            tetriminorenderer.cxx 
            tetris.cxx
            text.cxx
            texturefile.cxx
            texturememory.cxx
            window.cxx
            memoryrwops.cxx
            veramonobold.cxx
)

bmpToCxx(bluemino blueMinoBMP)
bmpToCxx(cyanmino cyanMinoBMP)
bmpToCxx(greenmino greenMinoBMP)
bmpToCxx(orangemino orangeMinoBMP)
bmpToCxx(purplemino purpleMinoBMP)
bmpToCxx(redmino redMinoBMP)
bmpToCxx(yellowmino yellowMinoBMP)

wavToCxx(collision collisionWAV)
wavToCxx(gameover gameOverWAV)
wavToCxx(move moveWAV)
wavToCxx(rotate rotateWAV)
wavToCxx(rowfull rowFullWAV)

ttfToCxx(veramonobold veraMonoBoldTTF)

add_executable(tetris ${sources})
target_compile_options(tetris PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetris PRIVATE ${CMAKE_CURRENT_BINARY_DIR} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetris ${SDL2_LIBRARIES} )
