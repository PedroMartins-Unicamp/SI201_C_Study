#include <stdlib.h>
#include <stdio.h>

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

#ifndef IMPORT_PRIORITY_QUEUE_H
    #include "include/data_structures/priorityQueue.h"
#endif

#ifndef IMPORT_MULTI_PRIORITY_QUEUE_H
    #include "include/data_structures/multiPriorityQueue.h"
#endif

void clear()
{
    system("clear");
}

int main(void)
{
    int priorityQtd;
    printf("Quantidade de Prioridades: ");
    scanf("%d", &priorityQtd);

    MPQueue *mPQueue = newMPQueue(priorityQtd);

    while(1)
    {
        clear();

        int opt;

        printf("Digite:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Imprimir Fila de Prioridades\n");
        printf("4 - Sair\n\n");

        printf("> ");
        scanf("%d", &opt);

        switch (opt) 
        {  
            case 1:
                clear();
                printf("-----Inserindo Elemento-----\n");

                int value, priority;
                printf("Valor inteiro: ");
                scanf("%d", &value);
                printf("Prioridade (max=0, min=%d): ", priorityQtd-1);
                scanf("%d", &priority);

                mPQueue_append(mPQueue, value, priority);

                printf("Valor %d inserido na fila de prioridade %d com sucesso...", value, priority);
                getchar();
                getchar();

                break;

            case 2:
                clear();
                printf("-----Removendo Elemento-----\n");

                if(mPQueue_isEmpty(mPQueue))
                {
                    printf("Nao ha elementos para remover...");
                    getchar();
                    getchar();
                }
                else
                {
                    int *indexValue = mPQueue_pop(mPQueue);
                    printf("Elemento %d removido da pilha %d com sucesso...", indexValue[1], indexValue[0]);
                    free(indexValue);
                    getchar();
                    getchar();
                }
                    
                break;


            case 3:
                clear();
                printf("Pilha de Multiplas Prioridades: \n");
                mPQueue_print(mPQueue);

                printf("Continue...");
                getchar();
                getchar();

                break;

            case 4:
                printf("PROGRAMA ENCERRADO");
                exit(0);
                break;

            default:
                clear();

                printf("Opcao invalida, insira uma opcao valida...");
                getchar();
                getchar();

                break;
        }

    }


    return 0;
}
