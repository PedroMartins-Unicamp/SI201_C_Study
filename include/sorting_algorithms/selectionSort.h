#define IMPORT_SELECTION_SORT_H

#include <stdlib.h>

void selectionSort(int *array, int size)
{
    if(size > 1)
    {
        for(int maxIndex = size-1; maxIndex > 1; maxIndex--)
        {
            int maxTermPos = maxIndex;
            for(int j = 0; j < maxIndex; j++)
            {
                if(array[maxTermPos] < array[j])
                    maxTermPos = j;
            }
            int aux = array[maxTermPos];
            array[maxTermPos] = array[maxIndex];
            array[maxIndex] = aux;
        }
    }
}

void selectionSortRecursive(int *array, int size)
{
    if(size > 1)
    {
        int maxIndex = size-1;
        int maxTermPos = maxIndex;

        for(int i = 0; i < maxIndex; i++)
        {
            if(array[maxTermPos] < array[i])
                maxTermPos = i;
        }
        int aux = array[maxTermPos];
        array[maxTermPos] = array[maxIndex];
        array[maxIndex] = aux;

        selectionSortRecursive(array, size-1);
    }
}