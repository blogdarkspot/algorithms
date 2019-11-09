cmake_minimum_required(VERSION 3.12)

project(Algorithms DESCRIPTION "" VERSION 1.0.0 LANGUAGES CXX C)

option(PACKAGE_TESTS "build this tests" ON)
option(PACKAGE_BENCHMARK "build with benchmark test" ON)

add_subdirectory(src)

if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
    
if(PACKAGE_BENCHMARK)
    add_subdirectory(benchmark)
endif()