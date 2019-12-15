set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/tetrimino.cxx 
    ${PROJECT_SOURCE_DIR}/src/minorenderer.cxx
    ${PROJECT_SOURCE_DIR}/src/minotexturestore.cxx
    ${PROJECT_SOURCE_DIR}/src/renderer.cxx
    ${PROJECT_SOURCE_DIR}/src/sdl.cxx
    ${PROJECT_SOURCE_DIR}/src/tetriminorenderer.cxx 
    ${PROJECT_SOURCE_DIR}/src/texturefile.cxx 
    ${PROJECT_SOURCE_DIR}/src/window.cxx
    ${PROJECT_SOURCE_DIR}/src/texturememory.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/bluemino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/cyanmino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/greenmino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/orangemino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/purplemino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/redmino.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/yellowmino.cxx
    ${PROJECT_SOURCE_DIR}/src/memoryrwops.cxx
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
