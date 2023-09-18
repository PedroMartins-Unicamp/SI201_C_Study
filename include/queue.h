#define IMPORT_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

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


int queue_isEmpty(Queue *queue)
{
    return ((queue->start==NULL) && (queue->end==NULL));
}

int queue_size(Queue *queue)
{
    if(queue_isEmpty(queue))
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

void queue_append(Queue *queue, int value)
{
    Node *node = newNode(value);

    if(queue_isEmpty(queue))
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

int queue_pop(Queue *queue)
{
    if(!queue_isEmpty(queue))
    {
        int value = queue->start->value;

        Node *node = queue->start;
        if(queue_size(queue) == 1)
        {
            queue->start = NULL;
            queue->end = NULL;
        }
        else
        {
            queue->start = queue->start->next; // error if len = 1
        }

        free(node);

        return value;
    }
    else 
    {
        exit(EMPTY_ARRAY);
    }
}

void queue_print(Queue *queue)
{
    if(queue_isEmpty(queue))
        printf("EMPTY QUEUE\n");
    else
    {
        Node *aux = queue->start;
        while(aux->next!=NULL)
        {
            printf("%d, ", aux->value);
            aux = aux->next;
        }
        printf("%d\n", aux->value);
    }
}

