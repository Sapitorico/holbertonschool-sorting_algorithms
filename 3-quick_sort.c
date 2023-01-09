#include "sort.h"
int partition(int *array, int lower, int higher, size_t size);
void quick_sort_recursion(int *array, int lower, int higher, size_t size);
/**
 * quick_sort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array
 * Return: void function
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}
/**
 * quick_sort_recursion - recursive function to sort an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: Array of integers to be sorted
 * @lower: lower index of the array
 * @higher: higher index of the array
 * @size: size of the array
 * Return: void function
 */
void quick_sort_recursion(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = lomuto_partition(array, lower, higher, size);
		quick_sort_recursion(array, lower, l_p - 1, size);
		quick_sort_recursion(array, l_p + 1, higher, size);
	}
}
/**
 * partition - partition the array and return the pivot index
 * @array: Array of integers to be sorted
 * @lower: lower index of the array
 * @higher: higher index of the array
 * @size: size of the array
 * Return: void function
 */
int partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
			++i;
		}
	}
	if (array[i] != array[higher])
	{
		aux = array[i];
		array[i] = array[higher];
		array[higher] = aux;
		print_array(array, size);
	}
	return (i);
}
