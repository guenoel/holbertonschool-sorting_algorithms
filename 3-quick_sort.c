#include "sort.h"

/**
 * swap - swap function
 * @a: node a
 * @b: node b
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - function to check and swith pivot
 * @array: array
 * @low: low value
 * @high: high value
 * @size: size of array
 * Return: i
 */

int partition(int array[], int low, int high, size_t size)
{
	int pivot, i, j;

	i = low;
	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			if (j != i)
				print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);
	return (i);
}

/**
 * recur_quick - quick sort function
 * @array: ...
 * @low: low value
 * @high: high value
 * @size: size of array
 */

void recur_quick(int array[], int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		recur_quick(array, low, pivot - 1, size);
		recur_quick(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - recursive quick sort
 * @array: array
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	recur_quick(array, 0, size - 1, size);
}
