#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

#ifndef IMPORT_NODE_H
    #include "include/node.h"
#endif


typedef struct linkedList
{
    Node *start;
} LinkedList;
LinkedList* newLinkedList()
{
    LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));

    linkedList->start = NULL;

    return linkedList;
}


int linkedList_isEmpty(LinkedList *linkedList)
{
    return linkedList->start == NULL;
}

int linkedList_size(LinkedList*linkedList)
{
    if(linkedList_isEmpty(linkedList))
        return 0;

    int counter = 1;
    Node *aux = linkedList->start;

    while(aux->next!=NULL)
    {
        counter++;
        aux = aux->next;
    }

    return counter;
}

Node* linkedList_getReference(LinkedList *linkedList, int index)
{
    if(linkedList_size(linkedList)-1 < index)
        exit(ERROR_LINKED_LIST_INDEX_OUT_OF_RANGE);
    else
    {

        Node *aux = linkedList->start;
        for(int i = 0; i<index; i++)
            aux = aux->next;
        
        return aux;
    }
}

void linkedList_append(LinkedList *linkedList, int value)
{
    Node *node = newNode(value);

    if(linkedList_isEmpty(linkedList))
        linkedList->start = node;
    else
    {
        Node *aux = linkedList->start;
        while(aux->next!=NULL)
            aux = aux->next;

        aux->next = node;
    }
}

int linkedList_remove(LinkedList *linkedList, int index)
{
    if(linkedList_isEmpty(linkedList))
        exit(ERROR_EMPTY_LINKED_LIST);

    int listSize = linkedList_size(linkedList);
    if(listSize-1 < index)
        exit(ERROR_LINKED_LIST_INDEX_OUT_OF_RANGE);
    
    
    int value;
    Node *aux;

    if(listSize == 1)
    {
        aux = linkedList->start;
        value = aux->value;
        linkedList->start = NULL;

        free(aux);
        return value;
    }

    Node *previous = linkedList_getReference(linkedList, index-1);
    aux = previous->next;
    previous->next = aux->next;

    value = aux->value;

    free(aux);
    return value;   
}

void linkedList_set(LinkedList *linkedList, int value, int index)
{
    if(linkedList_isEmpty(linkedList))
        exit(ERROR_EMPTY_LINKED_LIST);
    
    if(linkedList_size(linkedList)-1 < index)
        exit(ERROR_LINKED_LIST_INDEX_OUT_OF_RANGE);
    
    Node *node = linkedList_getReference(linkedList, index);
    node->value = value;
}

void linkedList_insert(LinkedList *linkedList, int value, int index)
{
    if(index==0)
    {
        node->next = linkedList->start;
        linkedList->start = node;
    }
    else
    {
        if(linkedList_isEmpty(linkedList))
            exit(ERROR_EMPTY_LINKED_LIST)
        
        if(linkedList_size(linkedList)-1 < index)
            exit(ERROR_LINKED_LIST_INDEX_OUT_OF_RANGE)
    
        Node *node = newNode(value);

        Node *previous = linkedList_getReference(linkedList, index-1);
        Node *aux = previous->next;
        
        node->next = aux;
        previous->next = node;
    }
}

void linkedList_reverse(LinkedList *linkedList)
{
    if(linkedList_isEmpty(linkedList) || linkedList_size(linkedList)==1)
    {
        return;
    }
    else
    {
        Node *aux1 = linkedList->start;
        Node *aux2 = aux1->next;

        linkedList->start->next = NULL;

        do
        {
            aux1 = aux2;
            aux2 = aux2->next;

            aux1->next = linkedList->start;
            linkedList->start = aux1
        }while(aux2!=NULL);
    }
}

int linkedList_getIndex(LinkedList *linkedList, int key)
{
    if(linkedList_isEmpty(linkedList))
        return -1;

    Node *aux = linkedList->start;
    int pos = 0;

    while(aux->value!=key)
    {
        aux = aux->next;
        pos++;

        if(aux==NULL)
            return -2;
    }

    return pos;
}

void linkedList_removeAllKey(LinkedList *linkedList, int key)
{
    int index = linkedList_getIndex(linkedList, key);

    while(index > 0)
    {
        linkedList_remove(linkedList, linkedList_getIndex(linkedList, key))
        int index = linkedList_getIndex(linkedList, key);
    }
}

void linkedList_print(LinkedList *linkedList)
{
    if(linkedList_isEmpty(linkedList))
        printf("EMPTY LINKED LIST\n");
    else
    {
        Node *aux = linkedList->start;

        printf("[%d", aux->value);
        while(aux->next!=NULL)
        {
            aux = aux->next;
            printf(", %d", aux->value);
        }
        printf("] (size: %d)\n", linkedList_size(linkedList));
    }
}

