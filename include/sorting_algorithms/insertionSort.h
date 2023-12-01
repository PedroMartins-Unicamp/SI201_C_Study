#define IMPORT_SELECTION_SORT_H

#include <stdlib.h>

void insertionSort(int *array, int size)
{
    if(size > 1)
    {
        for(int maxIndex = 1; maxIndex < size-1; maxIndex++)
        {
            int i = maxIndex;
            while((array[i] < array[i-1]) && (i > 0))
            {
                int aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;

                i--;
            }
        }
    }
}