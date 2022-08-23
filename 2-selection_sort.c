#include "sort.h"

/**
 * selection_sort - alg to sort in ascending order
 * @array: array
 * @size: array size
 * Return: void
 */


void selection_sort(int *array, size_t size)
{
	size_t test = 1, tmp, i, j;

	if (!(array))
		exit(EXIT_FAILURE);

	while (test != 0)
	{
		test = 0;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (array[i] > array[j])
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
					test++;
					print_array(array, size);
				}
			}
		}
	}

}
