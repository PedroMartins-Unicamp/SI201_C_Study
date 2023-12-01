#define IMPORT_BINARY_SEARCH_H

#include <stdlib.h>

int binarySearch(int *array, int size, int key)
{
    int start = 0;
    int maxIndex = size-1;

    while(start<=maxIndex)
    {
        int middle = (start+maxIndex)/2;

        if(array[middle] == key)
            return middle;

        if(key < array[middle])
            maxIndex = middle-1;
        else
            start = middle+1;
    }

    return -1;
}