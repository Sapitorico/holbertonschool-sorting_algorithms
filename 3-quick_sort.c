#include "sort.h"
void quick_sort(int *array, size_t size)
{
    int start = 0;
    int end = size - 1;

    if (start < end)
    {
        int pivot = partition(array, start, end);
        quick_sort(array, pivot);
        quick_sort(array + pivot + 1, size - 1 - pivot);
    }
}

int partition(int *array, int start, int end)
{
    int pivot = array[end];
    int i = start;

    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            swap(&array[i], &array[j]);
            printf("Swapped elements: [ %d, %d ]\n", array[i], array[j]);
            i++;
        }
    }
    swap(&array[i], &array[end]);
    printf("Swapped elements: [ %d, %d ]\n", array[i], array[end]);

    return i;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
