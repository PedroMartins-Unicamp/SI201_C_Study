#define IMPORT_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_NODE_H
    #include "include/node.h"
#endif

typedef struct queue
{
    Node *start;
    Node *end;
} Queue;
Queue* newQueue()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->start = NULL;
    queue->end = NULL;

    return queue;
}

int is_empty(Queue *queue)
{
    return ((queue->start==NULL) && (queue->end==NULL));
}

int size(Queue *queue)
{
    if(is_empty(queue))
        return 0;
    else
    {
        int size = 1;
        Node *node = queue->start;
        while(node->next!=NULL)
        {
            size++;
            
            node = node->next;
        }
        return size;
    }
}

void append(Queue *queue, int value)
{
    Node *node = newNode(value);

    if(is_empty(queue))
    {
        queue->start = node;
        queue->end = node;
    }
    else
    {
        queue->end->next = node;
        queue->end = node;
    }
}

int pop(Queue *queue)
{
    if(!is_empty(queue))
    {
        int value = queue->start->value;

        Node *node = queue->start;
        queue->start = queue->start->next;
        free(node);

        return value;
    }
    else 
    {
        exit(EMPTY_ARRAY);
    }
}

void print_queue(Queue *queue)
{
    Node *aux = queue->start;
    
    if(!is_empty(queue))
    {
        while(aux->next!=NULL)
        {
            printf("%d, ", aux->value);
            aux = aux->next;
        }
        printf("%d\n", aux->value);
    }
    else
        printf("EMPTY\n");
}

