#include <stdio.h>
#include <stdlib.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

#ifndef IMPORT_NODE_H
    #include "include/data_structures/node.h"
#endif

#ifndef IMPORT_STACK_H
    #include "include/data_structures/stack.h"
#endif

#ifndef IMPORT_QUEUE_H
    #include "include/data_structures/queue.h"
#endif

#ifndef IMPORT_LINKED_LIST_H
    #include "include/data_structures/linkedList.h"
#endif


int main(void)
{
    LinkedList *list = newLinkedList();

    linkedList_print(list);
    linkedList_append(list, 31);

    linkedList_print(list);
    linkedList_append(list, 23);

    linkedList_print(list);
    linkedList_append(list, 35);

    linkedList_print(list);
    linkedList_append(list, 56);

    linkedList_print(list);
    linkedList_append(list, 102);

    linkedList_print(list);
    linkedList_append(list, 1);

    linkedList_print(list);

    return 0;
}