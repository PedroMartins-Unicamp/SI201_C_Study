#define IMPORT_TREE_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int value;

    struct tnode *left;
    struct tnode *right;
} TNode;
TNode* newTNode(int value)
{
    TNode *node = (TNode*)malloc(sizeof(TNode));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}