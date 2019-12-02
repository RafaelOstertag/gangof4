pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_ttf)

add_executable(tetris tetris.cxx tetrimino.cxx)
target_compile_options(tetris PRIVATE ${SDL2_CFLAGS_OTHER})
target_include_directories(tetris PRIVATE "${PROJECT_BINARY_DIR}" PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(tetris ${SDL2_LIBRARIES} )
