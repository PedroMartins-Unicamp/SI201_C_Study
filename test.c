#include <stdlib.h>
#include <stdio.h>

#include "include/sorting_algorithms/selectionSort.h"
#include "include/sorting_algorithms/bubbleSort.h"
#include "include/sorting_algorithms/insertionSort.h"
#include "include/sorting_algorithms/mergeSort.h"

#include "include/search/binarySearch.h"


#define MAX 11

void print_array(int *array)
{
    printf("[%d", array[0]);
    for(int i = 1; i < MAX; i++)
        printf(", %d", array[i]);
    printf("]\n");
}

int main(void)
{
    int array[MAX] = {5, 11, 16, 2, 8, 7, 22, 9, 9, 4, 18};

    printf("Before Sorting: ");
    print_array(array);
    printf("\n");

    mergeSort(array, MAX);

    printf("After Sorting: ");
    print_array(array);

    printf("\n");

    int key;
    printf("element to search: ");
    scanf("%d", &key);

    int position = binarySearch(array, MAX, key);
    if(position == -1)
        printf("Element not found!\n");
    else
        printf("%d found at position %d.\n", key, position);

    return 0;
}