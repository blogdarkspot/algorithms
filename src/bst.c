#include"binary_search_tree.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

static int size_tree = 0;

void __search_minimum_node(struct Node *tree, int *key, void *data)
{
    struct Node *tmp = tree;
    while(tmp != NULL && tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    if(tmp != NULL)
    {
        data = tmp->data;
        *key = *(tmp->key);
    }
}

struct Node* __search_sucessor_node(struct Node *node)
{
    if(node != NULL && node->right != NULL)
    {
        struct Node *tmp = node->right;
        while(tmp != NULL && tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        return tmp;
    }

    struct Node *pTmp = node->parent;
    struct Node *cTmp = node;

    while (pTmp != NULL && pTmp->right != cTmp)
    {
        cTmp = pTmp;
        pTmp = pTmp->parent;
    }
    return pTmp;
}

struct Node* __search_node(struct Node* tree, int key)
{
    struct Node* tmp = tree;
    while (tmp != NULL && *(tmp->key) != key) {
        if (*(tmp->key) > key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return tmp;
}

struct Node* __search_predecessor_node(struct Node* node)
{
    if (node != NULL && node->left!= NULL) {
        struct Node* tmp = node->left;
        while (tmp != NULL && tmp->right != NULL) {
            tmp = tmp->right;
        }
        return tmp;
    }

    struct Node* pTmp = node->parent;
    struct Node* cTmp = node;

    while (pTmp != NULL && pTmp->left != cTmp) {
        cTmp = pTmp;
        pTmp = pTmp->parent;
    }
    return pTmp;
}

int __create_new_node(struct Node** node, struct Node* parent, int key, void* data)
{
    *node = malloc(sizeof(struct Node));
    int ret = ERR_NO_ERROR;
    if (*node != NULL) {

        (*node)->key = malloc(sizeof(int));

        if ((*node)->key != NULL) {
            memset((*node), 0, sizeof(struct Node));
            *((*node)->key) = key;
            (*node)->data = data;
            (*node)->parent = parent;

        } else {
            ret = ERR_CREATE_KEY;
        }
    } else {
        ret = ERR_CREATE_NODE;
    }
    return ret;
}

void search_value_by_key(struct Node *tree, int key, void *data)
{
    struct Node *tmp = tree;
    while(tmp != NULL && *(tmp->key) != key)
    {
        if(*(tmp->key) > key)
        {
            tmp = tmp->right;
        }
        else
        {
            tmp = tmp->left;
        }
        
    }
    if(tmp != NULL)
        data = tmp->data;
}

void search_minimum_key_and_value(struct Node *tree, int *key, void *data)
{
    struct Node *tmp = tree;
    while(tmp != NULL && tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    if(tmp != NULL)
    {
        data = tmp->data;
        *key = *(tmp->key);
    }
}

void search_maximum_key_and_value(struct Node *tree, int *key, void *data)
{
    struct Node *tmp = tree;
    while(tmp != NULL && tmp->right != NULL)
    {
        tmp = tmp->right;
    }
    if(tmp != NULL)
    {
        data = tmp->data;
        *key = *(tmp->key);
    }
}

void search_sucessor_key_and_value(struct  Node *tree, int key, int *sKey, void *sData)
{
    struct Node *tmp = __search_node(tree, key) ;

    if(tmp != NULL)
    {
        struct Node *sucessor = __search_sucessor_node(tmp);
        if(sucessor != NULL)
        {
            *sKey = *(sucessor->key);
            sData = sucessor->data;
        }
    }
}

void search_predecessor_key_and_value(struct Node *tree, int key, int *sKey, void *sData)
{
    struct Node *tmp = __search_node(tree, key) ;

    if(tmp != NULL)
    {
        struct Node *predecessor = __search_predecessor_node(tmp);
        if(predecessor != NULL)
        {
            *sKey = *(predecessor->key);
            sData = predecessor->data;
        }
    }
}

void create_tree(struct Node** root)
{
    *root = malloc(sizeof(struct Node));
    (*root)->parent = NULL;
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->key =  NULL;
    (*root)->data = NULL;
}

void __free_node(struct Node *node)
{
    if(node != NULL)
    {
        free(node->key);
        free(node);
        memset(node, 0, sizeof(struct Node));
    }
}

void free_tree(struct Node *root)
{
    if(root != NULL)
    {
        free_tree(root->left);
        free_tree(root->right);
        __free_node(root);
    }
}

void insert_node(struct Node *tree, int key, void *data)
{
    if(tree != NULL)
    {
        //tree empty
        if(tree->key == NULL)
        {
            tree->key = malloc(sizeof(int));
            *(tree->key) = key;
            tree->data = data;
        }
        else
        {
            struct Node *tmp = tree;
            struct Node *parent = tmp->parent;
            while(tmp != NULL)
            {
                parent = tmp;
                if(*(tmp->key) > key)
                {
                    tmp = tmp->left;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            if(*(parent)->key > key)
            {
                struct Node *n;
                __create_new_node(&n, parent, key, data);
                parent->left = n;
            }
            else 
            {
                struct Node *n;
                __create_new_node(&n, parent, key, data);
                parent->right = n;
            }
        }
        size_tree ++;
    }
}

int delete_node(struct Node* tree, int key)
{
    struct Node* node = __search_node(tree, key);
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            struct Node* parent = node->parent;
            if (parent != NULL) {
                if (parent->right == node) {
                    parent->right = NULL;
                } else {
                    parent->left = NULL;
                }
            }
        } else if (node->left != NULL && node->right == NULL) {
            node->left->parent = node->parent;
            node->left = NULL;
        } else if (node->right != NULL && node->left == NULL) {
            node->right->parent = node->parent;
            node->right = NULL;
        } else {
            struct Node* sucessor = __search_sucessor_node(node);
            if (sucessor == node->right) {
                node->parent->right = sucessor;
                sucessor->left = node->left;
            } else {
                sucessor->parent->left = sucessor->right;
                sucessor->parent = node->parent;
                sucessor->right = node->right;
                sucessor->left = node->left;
            }
        }
        __free_node(node);
        size_tree --;
    }
    return 0;
}

void inorder_tree_walk(struct Node *tree)
{
    if(tree != NULL)
    {
        inorder_tree_walk(tree->left);
        printf("%d ", *(tree->key));
        inorder_tree_walk(tree->right);
    }
}

void __get_inorder_tree(struct Node *root, int *key)
{
    if(root != NULL)
    {
        __get_inorder_tree(root->left, ++key);
        *key = *(root->key);
        __get_inorder_tree(root->right, ++key);
    }
}

void get_inorder_tree(struct Node *root, int **keys, int *size)
{
        *keys = malloc(sizeof(int) * size_tree);
        *size = size_tree;
        __get_inorder_tree(root, *keys);
}

void preorder_tree_walk(struct Node *tree)
{
    if(tree != NULL)
    {
        printf("%d ", *(tree->key));
        preorder_tree_walk(tree->left);
        preorder_tree_walk(tree->right);
    }
}

void postorder_tree_walk(struct Node *tree)
{
    if(tree != NULL)
    {
        postorder_tree_walk(tree->left);
        postorder_tree_walk(tree->right);
        printf("%d ", *(tree->key));
    }
}