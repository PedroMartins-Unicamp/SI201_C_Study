#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

#ifndef IMPORT_NODE_H
    #include "include/node.h"
#endif

#ifndef IMPORT_STACK_H
    #include "include/stack.h"
#endif

#ifndef IMPORT_QUEUE_H
    #include "include/queue.h"
#endif

#ifndef IMPORT_PRIORITY_QUEUE_H
    #include "include/priorityQueue.h"
#endif

#ifndef IMPORT_MULTI_PRIORITY_QUEUE_H
    #include "include/multiPriorityQueue.h"
#endif

int main(void)
{
    int priorityQtd;
    printf("Quantidade de Prioridades: ");
    scanf("%d", &priorityQtd);

    MPQueue *mPQueue = newMPQueue(priorityQtd);

    mPQueue_print(mPQueue);

    return 0;
}
