#define IMPORT_NODE_H

#include <stdlib.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

typedef struct node
{
    int value;
    struct node *next;
} Node;
Node* newNode(int value)
{
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->value = value;
    node->next = NULL;

    return node;
}