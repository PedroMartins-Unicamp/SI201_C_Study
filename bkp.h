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
List* newList(int max)
{
    List *list = (List*)malloc(sizeof(List));

    list->array = (int*)malloc(sizeof(int)*max);

    list->max = max;
    list->top = 0;

    return list;
}

void printList(List *list)
{
    printf("[");
    for(int i = 0; i < list->top; i++)
    {
        printf("%d", list->array[i]);
        if(i < list->top-1)
            printf(",");
    }
    printf("]\n");
}

void addList(List *list, int value)
{
    if(list->top==list->max)
    {
        printf("FULL LIST ERROR!");
        exit(0);
    }
    list->array[list->top++] = value;
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

void tNode_print(TNode *tNode)
{
    if(tNode!=NULL){
        tNode_print(tNode->left);
        printf(" %d",tNode->value);
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