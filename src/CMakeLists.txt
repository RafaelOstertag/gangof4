add_executable(tetris tetris.cxx tetrimino.cxx sdl.cxx window.cxx renderer.cxx blockletrenderer.cxx)
target_compile_options(tetris PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetris PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetris ${SDL2_LIBRARIES} )
