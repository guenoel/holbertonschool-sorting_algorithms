#include "sort.h"

/**
 * quick_sort - alg to sort
 * @array: array
 * @size: array size
 * Return: void
 */


void quick_sort(int *array, size_t size)
{
        size_t index = 0, a_index, i, j = 0;

        for (i = 0; i < size - 1; i++)
        {
                index = i;
                for (j = i + 1; j < size; j++)
                {
                        if (array[index] > array[j])
                                index = j;
                }
                if (index == i)
                        continue;
                if (index != i)
                {
                        a_index = array[i];
                        array[i] = array[index];
                        array[index] = a_index;
                }
                print_array(array, size);

        }
}
