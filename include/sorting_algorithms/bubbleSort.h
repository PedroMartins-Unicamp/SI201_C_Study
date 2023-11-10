#define IMPORT_BUBBLE_SORT_H

void bubbleSort(int *array, int size)
{
    for(int max_index = size-1; max_index > 1; max_index--)
    {
        for(int i = 0; i < max_index; i++)
        {
            if(array[i]>array[i+1])
            {
                int aux = array[i+1];
                array[i+1] = array[i];
                array[i] = aux;
            }
        }
    }
}

void bubbleSortRecursive(int *array, int size)
{
    if(size>1)
    {
        for(int i = 0; i < size; i++)
        {
            if(array[i]>array[i+1])
            {
                int aux = array[i+1];
                array[i+1] = array[i];
                array[i] = aux;
            }
        }

        bubbleSortRecursive(array, size-1);
    }
}


/*
Gabriel Cardoso dos Reis - 185671
Gabriel Mendes da Cruz - 195824
Sérgio Carlos - 195405



*/