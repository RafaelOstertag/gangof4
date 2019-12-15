enable_testing()

pkg_check_modules(CPPUNIT REQUIRED cppunit)

function(testSource name)
    add_executable(${name} ${name}.cxx ${PROJECT_SOURCE_DIR}/src/${name}.cxx)
    target_compile_options(${name} PRIVATE ${CPPUNIT_CFLAGS_OTHER} ${SDL2_CFLAGS_OTHER})
    target_include_directories(${name} PRIVATE "${PROJECT_SOURCE_DIR}/src" ${CPPUNIT_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})
    target_link_libraries(${name} ${CPPUNIT_LDFLAGS} ${SDL2_LDFLAGS})

    add_test(NAME ${name} COMMAND ${name})
endfunction(testSource)

function(testHeader name)
    add_executable(${name} ${name}.cxx)
    target_compile_options(${name} PRIVATE ${CPPUNIT_CFLAGS_OTHER} ${SDL2_CFLAGS_OTHER})
    target_include_directories(${name} PRIVATE "${PROJECT_SOURCE_DIR}/src" ${CPPUNIT_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})
    target_link_libraries(${name} ${CPPUNIT_LDFLAGS} ${SDL2_LDFLAGS})

    add_test(NAME ${name} COMMAND ${name})
endfunction(testHeader)

testSource(tetrimino)
testHeader(mino)
