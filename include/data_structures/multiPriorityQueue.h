#define IMPORT_MULTI_PRIORITY_QUEUE_H

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

typedef struct mPQueue
{
    int maxIndex;
    Queue *priority;
} MPQueue;
MPQueue* newMPQueue(int prioritiesQtd)
{
    MPQueue *mPQueue = (MPQueue*)malloc(sizeof(MPQueue));

    mPQueue->maxIndex = prioritiesQtd-1;
    mPQueue->priority = (Queue*)malloc(sizeof(Queue)*prioritiesQtd);

    for(int i=0; i <= mPQueue->maxIndex; i++)
       mPQueue->priority[i] = *newQueue();
    
    return mPQueue;
}

int mPQueue_isEmpty(MPQueue *mPQueue)
{
    for(int prior=0; prior<=mPQueue->maxIndex; prior++)
        if(!(queue_isEmpty(&mPQueue->priority[prior])))
            return 0;
    return 1;
}

void mPQueue_append(MPQueue *mPQueue, int value, int prior)
{
    if(prior>mPQueue->maxIndex)
        exit(ERROR_MPQUEUE_MAXIMUM_PRIORITY_EXCEEDED);
    else
        queue_append(&mPQueue->priority[prior], value);
}

int* mPQueue_pop(MPQueue *mPQueue)
{
    for(int prior=0; prior<=mPQueue->maxIndex; prior++)
        if(!(queue_isEmpty(&mPQueue->priority[prior])))
        {
            int *indexValue = (int*)malloc(sizeof(int)*2);
            indexValue[0] = prior;
            indexValue[1] = queue_pop(&mPQueue->priority[prior]);
            return indexValue;
        }
}

void mPQueue_print(MPQueue *mPQueue)
{
    for(int prior=0; prior<=mPQueue->maxIndex; prior++)
    {
        printf("Prior[%d]: ", prior);
        queue_print(&mPQueue->priority[prior]);
    }
}

