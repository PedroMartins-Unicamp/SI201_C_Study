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

typedef struct list
{
    int *array;
    int top, max;
} List;

int tNode_size(TNode *tNode)
{
    if(tNode==NULL)
        return 0;

    int leftSize=tNode_size(tNode->left);
    int rightSize=tNode_size(tNode->right);

    return 1+leftSize+rightSize;
}

int tree_size(Tree *tree)
{
    if(tree->root == NULL)
        return 0;
    else
        return tNode_size(tree->root);
}

void tNode_addTNode(TNode *tNode, int value)
{
    if(value < tNode->value)
        if(tNode->left == NULL)
            tNode->left = newTNode(value);
        else
            tNode_addTNode(tNode->left, value);
    else
        if(tNode->right == NULL)
            tNode->right = newTNode(value);
        else
            tNode_addTNode(tNode->right, value);
}

void tree_addTNode(Tree *tree, int value)
{
    if(tree->root == NULL)
        tree->root = newTNode(value);
    else
        tNode_addTNode(tree->root, value);
}

TNode* tNode_getReferenceIterative(TNode *tNode, int key)
{
    TNode *aux = tNode;
    
    while(aux!=NULL)
    {
        if(aux->value == key)
            return aux;
        else if(key < aux->value)
            aux = aux->left;
        else
            aux = aux->right;
    }

    return NULL;
}

TNode* tree_getReferenceIterative(Tree *tree, int key)
{
    if(tree->root != NULL)
        return tNode_getReferenceIterative(tree->root, key);
    
    return NULL;
}

int tNode_height(TNode *tNode)
{
    if(tNode==NULL)
        return -1;
    
    int leftHeight = tNode_height(tNode->left);
    int rightHeight = tNode_height(tNode->right);
    if(leftHeight>rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}

int tree_height(Tree *tree)
{
    if(tree->root==NULL)
        return -1;
    
    return tNode_height(tree->root);
}

void tNode_print(TNode *tNode)
{
    if(tNode != NULL)
    {
        tNode_print(tNode->left);
        printf(" %d", tNode->value);
        tNode_print(tNode->right);
    }
}

void tree_print(Tree *tree)
{
    printf("[");
    if(tree->root != NULL)
        tNode_print(tree->root);
    printf(" ]\n");

}