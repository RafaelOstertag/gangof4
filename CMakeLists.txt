cmake_minimum_required(VERSION 3.10)

# set the project name
project(GangOf4 VERSION 1.2.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -pedantic -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-g0 -O3 -Wall -pedantic -Werror -DNDEBUG")

include(FindPkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_ttf SDL2_mixer)

function(bmpToCxx filename varName)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${filename}.cxx
        COMMAND ${CMAKE_BINARY_DIR}/utils/bin2cxx ${PROJECT_SOURCE_DIR}/resources/${filename}.bmp ${varName} ${filename} ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS bin2cxx
    )
endfunction(bmpToCxx)

function(wavToCxx filename varName)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${filename}.cxx
        COMMAND ${CMAKE_BINARY_DIR}/utils/bin2cxx ${PROJECT_SOURCE_DIR}/resources/${filename}.wav ${varName} ${filename} ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS bin2cxx
    )
endfunction(wavToCxx)

function(ttfToCxx filename varName)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${filename}.cxx
        COMMAND ${CMAKE_BINARY_DIR}/utils/bin2cxx ${PROJECT_SOURCE_DIR}/resources/${filename}.ttf ${varName} ${filename} ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS bin2cxx
    )
endfunction(ttfToCxx)

add_subdirectory(utils)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(it)

configure_file(gof_version.h.in gof_version.h)
configure_file(resources/gangof4.desktop.in gangof4.desktop)

install(FILES ${CMAKE_BINARY_DIR}/gangof4.desktop DESTINATION share/applications)
install(FILES ${PROJECT_SOURCE_DIR}/resources/gangof4.png DESTINATION share/icons/hicolor/48x48/apps)
