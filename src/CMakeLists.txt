cmake_minimum_required(VERSION 3.12)

add_library(BSTree)
target_include_directories(BSTree PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_sources(BSTree PRIVATE bst.c)

add_library(Algorithm::BSTree ALIAS BSTree)