#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#ifdef __cplusplus
extern "C" {
#endif 

#define ERR_NO_ERROR 0x00
#define ERR_CREATE_NODE 0x01
#define ERR_CREATE_KEY 0x02

/**
 * Let x be a Node in binary search tree. If y is a node in the left
 * subtree of x, then, y.key < x.key. If y is a node in the right 
 * subtree of x, then, y.key >= x.key
 * */
struct Node
{
    struct Node *parent;
    struct Node *left;
    struct Node *right;

    int *key;
    void *data;
};

typedef struct Node binary_tree;

void search_value_by_key(struct Node *tree, int key, void *data);

void search_minimum_key_and_value(struct Node *tree, 
                                    int *key, void *data);

void search_maximum_key_and_value(struct Node *tree, 
                                    int *key, void *data);

void search_sucessor_key_and_value(struct  Node *tree, 
                                    int key, int *sKey, void *sData);
                                    
void search_predecessor_key_and_value(struct Node *tree, 
                                    int key, int *sKey, void *sData);
                            
void create_tree(struct Node** root);

void insert_node(struct Node *tree, int key, void *data);

int delete_node(struct Node* tree, int key);

void inorder_tree_walk(struct Node *tree);

void get_inorder_tree(struct Node *tree, int **keys, int *size);

void preorder_tree_walk(struct Node *tree);

void postorder_tree_walk(struct Node *tree);
#ifdef __cplusplus
}
#endif
#endif
