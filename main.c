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
    #include "include/priority_queue.h"
#endif

int main(void)
{
    PQueue *p_queue = newPQueue();

    pQueue_print(p_queue);
    printf("\n");

    pQueue_append(p_queue, 10, 1);
    pQueue_append(p_queue, 20, 1);
    pQueue_append(p_queue, 30, 1);
    pQueue_append(p_queue, 40, 1);
    pQueue_append(p_queue, 50, 1);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_append(p_queue, 60, 0);
    pQueue_append(p_queue, 70, 0);
    pQueue_append(p_queue, 80, 0);
    pQueue_append(p_queue, 90, 0);
    pQueue_append(p_queue, 100, 0);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");
    
    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    pQueue_pop(p_queue);

    pQueue_print(p_queue);
    printf("\n");

    return 0;
}
