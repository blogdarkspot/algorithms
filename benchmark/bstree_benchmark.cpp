#include "binary_search_tree.h"
#include<benchmark/benchmark.h>

static void create_tree(benchmark::State& state)
{
    while(state.KeepRunning())
    {
        binary_tree *tree = NULL;
        create_tree(&tree);
    }
}

static void insert_tree(benchmark::State& state)
{

    binary_tree *tree = NULL;
    create_tree(&tree);
    int i = 1;
    while(state.KeepRunning())
    {
        insert_node(tree, i++, NULL);
    }
}

BENCHMARK(create_tree);
BENCHMARK(insert_tree);

BENCHMARK_MAIN();