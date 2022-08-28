#include "sort.h"

/**
 * shell_sort - shell sort knuth sequence
 * @array: array
 * @size: size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	int low, high;
	int tmp, h = 1;
	int n = (int)size;

	while(h <= n / 3)
	{
		h = (h * 3) + 1;
	}

	while (h > 0)
	{
		for (high = h; high < n; high++)
		{
			tmp = array[high];
			low = high;
			while (low > h - 1 && array[low - h] >= tmp)
			{
				array[low] = array[low - h];
				low = low - h;
			}
			array[low] = tmp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
