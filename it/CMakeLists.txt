set(SOURCES 
    ${CMAKE_CURRENT_BINARY_DIR}/bluemino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/cyanmino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/greenmino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/orangemino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/purplemino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/redmino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/yellowmino.cxx
    ${PROJECT_SOURCE_DIR}/src/sdl/memoryrwops.cxx
    ${PROJECT_SOURCE_DIR}/src/sdl/renderer.cxx
    ${PROJECT_SOURCE_DIR}/src/sdl/sdl.cxx
    ${PROJECT_SOURCE_DIR}/src/sdl/texturefile.cxx 
    ${PROJECT_SOURCE_DIR}/src/sdl/texturememory.cxx
    ${PROJECT_SOURCE_DIR}/src/sdl/window.cxx
    ${PROJECT_SOURCE_DIR}/src/tetrimino/minorenderer.cxx
    ${PROJECT_SOURCE_DIR}/src/tetrimino/minotexturestore.cxx
    ${PROJECT_SOURCE_DIR}/src/tetrimino/tetrimino.cxx 
    ${PROJECT_SOURCE_DIR}/src/tetrimino/tetriminorenderer.cxx 
)

bmpToCxx(bluemino blueMinoBMP)
bmpToCxx(cyanmino cyanMinoBMP)
bmpToCxx(greenmino greenMinoBMP)
bmpToCxx(orangemino orangeMinoBMP)
bmpToCxx(purplemino purpleMinoBMP)
bmpToCxx(redmino redMinoBMP)
bmpToCxx(yellowmino yellowMinoBMP)

add_executable(tetriminorenderer tetriminorenderer.cxx ${SOURCES})
target_compile_options(tetriminorenderer PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetriminorenderer PRIVATE ${PROJECT_SOURCE_DIR}/src ${CMAKE_CURRENT_BINARY_DIR} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetriminorenderer ${SDL2_LDFLAGS} )

add_executable(minorenderer minorenderer.cxx ${SOURCES})
target_compile_options(minorenderer PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(minorenderer PRIVATE ${PROJECT_SOURCE_DIR}/src ${CMAKE_CURRENT_BINARY_DIR} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(minorenderer ${SDL2_LDFLAGS} )
