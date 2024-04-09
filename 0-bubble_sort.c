#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bubble_sort - Sorts with bubbles.
 *
 * @array: Array to sort.
 *
 * @size: Size of array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			while (i < size - 1 && array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;

				print_array(array, size);
				i += 1;
			}
			i = -1;
		}
	}
}



