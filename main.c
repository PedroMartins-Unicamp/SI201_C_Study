#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

#ifndef IMPORT_NODE_H
    #include "include/node.h"
#endif

#ifndef IMPORT_QUEUE_H
    #include "include/queue.h"
#endif

int main(void)
{
    Queue *queue = newQueue();

    print_queue(queue);

    append(queue, 1);

    print_queue(queue);

    append(queue, 2);
    append(queue, 3);
    append(queue, 4);

    print_queue(queue);

    pop(queue);

    print_queue(queue);

    return 0;
}
