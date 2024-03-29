#include "binary_search_tree.h"
#include <gtest/gtest.h>
#include <cstdlib>
#include <cstdio>

void test_create_new_tree()
{
    binary_tree *tree = NULL;
    create_tree(&tree);

}

void test_add_tree_nodes()
{
    binary_tree *tree = NULL;
    create_tree(&tree);
    insert_node(tree, 3, NULL);
    insert_node(tree, 1, NULL);
    insert_node(tree, 4, NULL);
    insert_node(tree, 8, NULL);
}

void test_add_tree_nodes_delete_leaf()
{
    binary_tree *tree = NULL;
    create_tree(&tree);
    insert_node(tree, 3, NULL);
    insert_node(tree, 1, NULL);
    insert_node(tree, 4, NULL);
    insert_node(tree, 8, NULL);
    delete_node(tree, 8);
    inorder_tree_walk(tree);
}

void test_add_five_nodes_delete_leaf()
{
    binary_tree *tree = NULL;
    create_tree(&tree);
    insert_node(tree, 3, NULL);
    insert_node(tree, 1, NULL);
    insert_node(tree, 5, NULL);
    insert_node(tree, 4, NULL);
    insert_node(tree, 8, NULL);
    delete_node(tree, 4);
    inorder_tree_walk(tree);
}

void test_add_five_nodes_delete_leaf_two()
{
    binary_tree *tree = NULL;
    create_tree(&tree);
    insert_node(tree, 3, NULL);
    insert_node(tree, 1, NULL);
    insert_node(tree, 6, NULL);
    insert_node(tree, 4, NULL);
    insert_node(tree, 5, NULL);
    insert_node(tree, 9, NULL);
    delete_node(tree, 6);
    postorder_tree_walk(tree);
}



int main(int argc, char **argv)
{
    test_add_five_nodes_delete_leaf_two();
    return 0;
}