#define IMPORT_STACK_H

#include <stdlib.h>
#include <stdio.h>

#ifndef IMPORT_ERROR_H
    #include "include/error.h"
#endif

#ifndef IMPORT_NODE_H
    #include "include/data_structures/node.h"
#endif

typedef struct stack
{
    Node *top;
} Stack;
Stack* newStack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    stack->top = NULL;

    return stack;
}


int stack_isEmpty(Stack *stack)
{
    return (stack->top==NULL);
}

int stack_size(Stack *stack)
{
    if(stack_isEmpty(stack))
        return 0;
    else
    {
        int size = 1;
        Node *node = stack->top;
        while(node->next!=NULL)
        {
            size++;
            node = node->next;
        }
        return size;
    }
}

void stack_append(Stack *stack, int value)
{
    Node *node = newNode(value);

    if(stack_isEmpty(stack))
        stack->top = node;
    else
    {
        node->next = stack->top;
        stack->top = node;
    }
}

int stack_pop(Stack *stack)
{
    if(stack_isEmpty(stack))
        exit(ERROR_EMPTY_STACK);
    else
    {
        Node *aux = stack->top;
        stack->top = stack->top->next;

        int value = aux->value;

        free(aux);
        return value;
    }
}

void stack_print(Stack *stack)
{
    if(stack_isEmpty(stack))
        printf("EMPTY STACK\n");
    else
    {
        Node *aux = stack->top;
        while(aux->next!=NULL)
        {
            printf("%d, ", aux->value);
            aux = aux->next;
        }
        printf("%d\n", aux->value);
    }
}