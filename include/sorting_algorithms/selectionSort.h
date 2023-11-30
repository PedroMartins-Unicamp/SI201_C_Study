#define IMPORT_SELECTION_SORT_H

#include <stdlib.h>

void selectionSort(int *array, int size)
{
    for(int maxIndex = size-1; maxIndex > 1; maxIndex-- )
    {
        int maxTermPos = 0;
        for(int i = 1; i <= maxIndex; i++)
            if(array[maxTermPos] < array[i])
                maxTermPos = i;

        int aux = array[maxIndex];
        array[maxIndex] = array[maxTermPos];
        array[maxTermPos] = aux;
    }
}

void selectionSortRecursive(int *array, int size)
{
    if(size > 1)
    {
        int maxIndex = size-1;

        int maxTermPos = 0;
        for(int i = 1; i <= maxIndex; i++)
            if(array[maxTermPos] < array[i])
                maxTermPos = i;
        
        int aux = array[maxIndex];
        array[maxIndex] = array[maxTermPos];
        array[maxTermPos] = aux;

        selectionSortRecursive(array, size-1);
    }
}