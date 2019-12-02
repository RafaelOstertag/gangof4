enable_testing()

pkg_check_modules(CPPUNIT REQUIRED cppunit)

function(test name)
    add_executable(${name} ${name}.cxx ${PROJECT_SOURCE_DIR}/src/${name}.cxx)
    target_compile_options(${name} PRIVATE ${CPPUNIT_CFLAGS_OTHER})
    target_include_directories(${name} PRIVATE "${PROJECT_SOURCE_DIR}/src" PUBLIC ${CPPUNIT_INCLUDE_DIRS})
    target_link_libraries(${name} ${CPPUNIT_LIBRARIES} )

    add_test(NAME ${name} COMMAND ${name})
endfunction(test)

test(tetrimino)

