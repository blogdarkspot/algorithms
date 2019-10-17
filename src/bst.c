#include"binary_search_tree.h"
#include<stdlib.h>
#include<stdio.h>

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
                if(*(tmp->key) < key)
                {
                    tmp = tmp->left;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            if(*(parent)->key < key)
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
    }
}

int delete_node(struct Node* tree, int key)
{
    struct Node* node = __search_node(tree, key);
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            //just remove the node
            struct Node* parent = node->parent;
            if (parent == NULL) {
                //root node just clear
                node->data = NULL;
                free(node->key);
                node->key = NULL;
            } else {
                if (parent->right == node) {
                    free(node->key);
                    node->key = NULL;
                    node->data = NULL;
                    node->parent = NULL;
                    free(node);
                    node = NULL;
                    parent->right = NULL;

                } else {
                    free(node->key);
                    node->key = NULL;
                    node->data = NULL;
                    node->parent = NULL;
                    free(node);
                    node = NULL;
                    parent->left = NULL;
                }
            }
        } else if (node->left != NULL && node->right == NULL) {
            node->left->parent = node->parent;
            node->left = NULL;
            free(node->key);
            node->key = NULL;
            node->data = NULL;
            free(node);
        } else if (node->right != NULL && node->left == NULL) {
            node->right->parent = node->parent;
            node->right = NULL;
            free(node->key);
            node->key = NULL;
            node->data = NULL;
            free(node);
        } else {
            struct Node* sucessor = __search_sucessor_node(node);
            if (sucessor == node->right) {
                struct Node* parent = node->parent;
                parent->right = sucessor;
                node->data = NULL;
                node->left = NULL;
                node->right = NULL;
                free(node->key);
                free(node);
                node->key = NULL;
                node = NULL;
            } else {
                sucessor->parent = node->parent;
                sucessor->left = node->left;
                node->right->left = sucessor->right;
                node->data = NULL;
                node->left = NULL;
                node->right = NULL;
                free(node->key);
                free(node);
                node->key = NULL;
                node = NULL;
            }
        }
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