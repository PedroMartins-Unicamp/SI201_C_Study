#define IMPORT_NODE_H

#include <stdlib.h>

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