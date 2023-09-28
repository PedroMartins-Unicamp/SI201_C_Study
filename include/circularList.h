#define IMPORT_CIRCULAR_LIST_H

#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

#ifndef IMPORT_NODE_H
    #include "include/node.h"
#endif

typedef struct circularList
{
    Node *start;
}CircularList;
CircularList* newCircularList()
{
    CircularList *circularList = (CircularList*)malloc(sizeof(CircularList));

    circularList->start = NULL;

    return circularList;
}

int circularList_isEmpty(CircularList *circularList)
{
    return circularList->start==NULL;
}

int circularList_size(CircularList *circularList)
{
    if(circularList_isEmpty(circularList))
        return 0;
    
    int counter = 1;
    Node *aux = circularList->start;

    while(aux->next!=NULL)
    {
        counter++
        aux = aux->next;
    }

    return counter;
}

void circularList_append(CircularList *circularList, int value)
{
    Node *node = newNode(value);
    if(circularList_isEmpty)
    {
        circularList->start = node;
        node->next = circularList->start;
    }

    node->next = circularList->start;
    Node *aux = circularList->start;

    while(aux->next!=circularList->start)
        aux = aux->next;
    
    aux->next = node;
}


void circularList_print(CircularList *cicularList)
{
    if(circularList_isEmpty(circularList))
        printf("EMPTY CIRCULAR LIST\n");
    else
    {
        Node *aux = circularList->start;

        printf("[%d", aux->value);
        while(aux->next!=circularList->start)
        {
            aux = aux->next;
            printf(", %d", aux->value);
        }
        printf("] (size: %d)\n", circularList_size(linkedList));
    }
}
