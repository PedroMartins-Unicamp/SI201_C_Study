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
    #include "include/data_structures/linked_list/linkedList.h"
#endif

#ifndef IMPORT_TREE_NODE_H
    #include "include/data_structures/tree/tnode.h"
#endif

#ifndef IMPORT_TREE_H
    #include "include/data_structures/tree/tree.h"
#endif

int main(void)
{
    Tree *tree = newTree();

    tree_print(tree);

    tree_addTNode(tree, 6);
    tree_print(tree);
    tree_addTNode(tree, 8);
    tree_print(tree);
    tree_addTNode(tree, 1);
    tree_print(tree);
    tree_addTNode(tree, 7);
    tree_print(tree);
    tree_addTNode(tree, 3);
    tree_print(tree);
    tree_addTNode(tree, 9);
    tree_print(tree);
    tree_addTNode(tree, 11);
    tree_print(tree);

    // int key;
    // printf("Search element: ");
    // scanf("%d", &key);
    // TNode *search = tree_getReferenceIterative(tree, key);
    // printf("Found: %d\n", search->value);
    
    printf("Tree size: %d\n", tree_size(tree));
    printf("Tree height: %d\n", tree_height(tree));

    return 0;
}


    // LinkedList *list = newLinkedList();

    // linkedList_print(list);
    // linkedList_append(list, 31);

    // linkedList_print(list);
    // linkedList_append(list, 23);

    // linkedList_print(list);
    // linkedList_append(list, 35);

    // linkedList_print(list);
    // linkedList_append(list, 56);

    // linkedList_print(list);
    // linkedList_append(list, 102);

    // linkedList_print(list);
    // linkedList_append(list, 1);

    // linkedList_print(list);