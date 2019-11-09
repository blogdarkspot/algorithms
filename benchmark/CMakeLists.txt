
cmake_minimum_required(VERSION 3.12)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/benchmark" "extern/benchmark")

add_executable(benchmarkBST)

target_sources(benchmarkBST PRIVATE bstree_benchmark.cpp)
target_compile_features(benchmarkBST PUBLIC cxx_std_17)
target_link_libraries(benchmarkBST BSTree benchmark)