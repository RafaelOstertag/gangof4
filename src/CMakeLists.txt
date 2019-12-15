set(sources 
            ${CMAKE_CURRENT_BINARY_DIR}/bluemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/collision.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/cyanmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/gameover.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/greenmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/move.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/orangemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/purplemino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/redmino.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/rotate.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/rowfull.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/rowfull.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/yellowmino.cxx
            board.cxx
            boardrenderer.cxx
            circulartetriminostock.cxx
            font.cxx
            game.cxx
            gangof4.cxx
            help.cxx
            labelvalue.cxx
            memoryrwops.cxx
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
            text.cxx
            texturefile.cxx
            texturememory.cxx
            veramonobold.cxx
            window.cxx
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

add_executable(gangof4 ${sources})
target_compile_options(gangof4 PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(gangof4 PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_BINARY_DIR} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(gangof4 ${SDL2_LDFLAGS})

install(TARGETS gangof4 DESTINATION bin)
