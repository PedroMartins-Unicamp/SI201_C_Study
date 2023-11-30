#define IMPORT_BUBBLE_SORT_H

#include <stdlib.h>

void bubbleSort(int *array, int size)
{
    for(int maxIndex = size-1; maxIndex > 1; maxIndex--)
    {
        for(int i = 0; i < maxIndex; i++)
        {
            if(array[i] > array[i+1])
            {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
        }
    }
}

void bubbleSortRecursive(int *array, int size)
{
    if(size > 1)
    {
        for(int i = 0; i < size; i++)
        {
            if(array[i] > array[i+1])
            {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
        }
        bubbleSortRecursive(array, size-1);
    }
}