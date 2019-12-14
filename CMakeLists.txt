cmake_minimum_required(VERSION 3.10)

# set the project name
project(Bounce VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -pedantic -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-g0 -O3 -Wall -pedantic -Werror -DNDEBUG")

include(FindPkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_ttf SDL2_mixer)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(it)
