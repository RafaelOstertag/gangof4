add_executable(tetriminorenderer tetriminorenderer.cxx 
    ${PROJECT_SOURCE_DIR}/src/tetrimino.cxx 
    ${PROJECT_SOURCE_DIR}/src/sdl.cxx 
    ${PROJECT_SOURCE_DIR}/src/renderer.cxx 
    ${PROJECT_SOURCE_DIR}/src/tetriminorenderer.cxx 
    ${PROJECT_SOURCE_DIR}/src/blockletrenderer.cxx
    ${PROJECT_SOURCE_DIR}/src/window.cxx)
target_compile_options(tetriminorenderer PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetriminorenderer PRIVATE "${PROJECT_SOURCE_DIR}/src" PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetriminorenderer ${SDL2_LIBRARIES} )

add_executable(blockletrenderer blockletrenderer.cxx ${PROJECT_SOURCE_DIR}/src/window.cxx ${PROJECT_SOURCE_DIR}/src/sdl.cxx ${PROJECT_SOURCE_DIR}/src/blockletrenderer.cxx ${PROJECT_SOURCE_DIR}/src/renderer.cxx)
target_compile_options(blockletrenderer PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(blockletrenderer PRIVATE "${PROJECT_SOURCE_DIR}/src" PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(blockletrenderer ${SDL2_LIBRARIES} )
