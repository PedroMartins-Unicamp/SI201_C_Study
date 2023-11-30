#define IMPORT_INSERTION_SORT_H

#include <stdlib.h>

void insertionSort(int *array, int size)
{
    if(size <= 1)
        return;

    int maxIndex = size-1;

    for(int i = 1; i <= maxIndex; i++)
    {
        int j = i;
        while((array[j] < array[j-1]) && (j > 0))
        {
            int aux = array[j];
            array[j] = array[j-1];
            array[j-1] = aux;

            j--;
        }
    }
}
