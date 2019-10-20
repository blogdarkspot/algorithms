cmake_minimum_required(VERSION 3.12)

project(Algorithms DESCRIPTION "" VERSION 1.0.0 LANGUAGES C)

option(PACKAGE_TESTS "build this tests" ON)

add_subdirectory(src)

if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
    