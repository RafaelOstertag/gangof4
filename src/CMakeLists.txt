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
            ${CMAKE_CURRENT_BINARY_DIR}/veramonobold.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/yellowmino.cxx
            board/board.cxx
            board/boardrenderer.cxx
            difficultyselector.cxx
            game/easygamefactory.cxx
            game/game.cxx
            game/hardgamefactory.cxx
            game/labelvalue.cxx
            game/mediumgamefactory.cxx
            game/preview.cxx
            gangof4.cxx
            intro.cxx
            pausetext.cxx
            scorer/fastadvancingscorer.cxx
            scorer/slowadvancingscorer.cxx
            sdl/font.cxx
            sdl/fontfactory.cxx
            sdl/memoryrwops.cxx
            sdl/renderer.cxx 
            sdl/sdl.cxx 
            sdl/soundfile.cxx
            sdl/soundmemory.cxx
            sdl/soundplayer.cxx
            sdl/text.cxx
            sdl/texturefile.cxx
            sdl/texturememory.cxx
            sdl/window.cxx
            tetrimino/circulartetriminostock.cxx
            tetrimino/hardtetriminostock.cxx
            tetrimino/minorenderer.cxx 
            tetrimino/minotexturestore.cxx
            tetrimino/randomtetriminostock.cxx
            tetrimino/tetrimino.cxx 
            tetrimino/tetriminorenderer.cxx 
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
