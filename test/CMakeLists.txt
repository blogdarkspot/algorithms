cmake_minimum_required(VERSION 3.12)

add_executable(BinaryTreeTest)
target_sources(BinaryTreeTest PRIVATE bstree_unit_test.c)
target_link_libraries(BinaryTreeTest BSTree)