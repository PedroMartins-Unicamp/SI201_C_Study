#define IMPORT_PRIORITY_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

#ifndef IMPORT_NODE_H
    #include "include/data_structures/node.h"
#endif

#ifndef IMPORT_QUEUE_H
    #include "include/data_structures/queue.h"
#endif

typedef struct pQueue
{
    Queue *prioritary;
    Queue *normal;
} PQueue;
PQueue* newPQueue()
{
    PQueue *pQueue = (PQueue*)malloc(sizeof(PQueue));

    pQueue->prioritary = newQueue();
    pQueue->normal = newQueue();

    return pQueue;
}

int pQueue_isEmpty(PQueue *pQueue)
{
    return (queue_isEmpty(pQueue->prioritary)&&(queue_isEmpty(pQueue->normal)));
}

int pQueue_prioritaryIsEmpty(PQueue *pQueue)
{
    return queue_isEmpty(pQueue->prioritary);
}

int pQueue_normalIsEmpty(PQueue *pQueue)
{
    return queue_isEmpty(pQueue->normal);
}

int pQueue_size(PQueue *pQueue)
{
    return queue_size(pQueue->prioritary)+queue_size(pQueue->normal);
}

void pQueue_append(PQueue *pQueue, int value, int isPrioritary)
{
    if(isPrioritary)
        queue_append(pQueue->prioritary, value);
    else
        queue_append(pQueue->normal, value);
}

int pQueue_pop(PQueue *pQueue)
{
    if(pQueue_prioritaryIsEmpty(pQueue))
        queue_pop(pQueue->normal);
    else
        queue_pop(pQueue->prioritary);
}

void pQueue_print(PQueue *pQueue)
{
    printf("Prioritary queue: ");
    queue_print(pQueue->prioritary);

    printf("Normal queue: ");
    queue_print(pQueue->normal);
}
