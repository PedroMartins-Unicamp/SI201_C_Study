#define IMPORT_MERGE_SORT_H

#include <stdlib.h>

void merge(int *array, int size, int *array1, int size1, int *array2, int size2)
{
    int arrayTop=0, array1Top=0, array2Top=0;

    while((array1Top < size1) && (array2Top < size2))
    {
        if(array1[array1Top] < array2[array2Top])
            array[arrayTop++] = array1[array1Top++];
        else
            array[arrayTop++] = array2[array2Top++];
    }

    while(array1Top < size1)
        array[arrayTop++] = array1[array1Top++];

    while(array2Top < size2)
        array[arrayTop++] = array2[array2Top++];
}


void mergeSort(int *array, int size)
{
    if(size > 1)
    {
        int leftHalfSize = size/2;
        int rightHalfSize = size - leftHalfSize;

        int *leftHalf = (int*)malloc(sizeof(int)*leftHalfSize);
        int *rightHalf = (int*)malloc(sizeof(int)*rightHalfSize);

        for(int i = 0; i < leftHalfSize; i++)
            leftHalf[i] = array[i];
        
        for(int i = 0; i < rightHalfSize; i++)
            rightHalf[i] = array[i+leftHalfSize];

        mergeSort(leftHalf, leftHalfSize);
        mergeSort(rightHalf, rightHalfSize);

        merge(array, size, leftHalf, leftHalfSize, rightHalf, rightHalfSize);

        free(leftHalf);
        free(rightHalf);
    }
}

