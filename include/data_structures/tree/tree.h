#define IMPORT_TREE_H

#include <stdlib.h>

#ifndef IMPORT_TREE_NODE_H
    #include "./tnode.h"
#endif

typedef struct tree
{
    TNode *root;
} Tree;
Tree* newTree()
{
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    
    tree->root = NULL;

    return tree;
}