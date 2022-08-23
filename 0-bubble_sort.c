#include "sort.h"

/**
 * bubble_sort - function to sort throught bubble method
 * @array: array
 * @size: size of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t n;
	int i = 1;
	int tmp;

	if (!(array) || size < 2)
		return;

	while (i != 0)
	{
		i = 0;
		for (n = 0, i = 0; n < (size - 1); n++)
		{
			if (array[n] > array[n + 1])
			{
				tmp = array[n];
				array[n] = array[n + 1];
				array[n + 1] = tmp;
				i++;
				print_array(array, size);
			}
		}
	}
}
