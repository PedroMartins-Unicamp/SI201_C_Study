#include <stdlib.h>
#include <stdio.h>

void selectionSort(int *array, int size)
{
    int end_index = size-1;

    for(int i = end_index; i > 0; i--)
    {
        int max_index = 0;
        for(int j = 1; j <= end_index; j++)
            if(array[j] > array[max_index])
                max_index = j;

        int aux = array[end_index];
        array[end_index] = array[max_index];
        array[max_index] = aux;
        
        end_index--;
    }
}
