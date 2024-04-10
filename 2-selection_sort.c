
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - Swaps the values of two integers.
 *
 * @xp: Pointer to the first integer.
 * @yp: Pointer to the second integer.
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 *
 * @array: Array to sort.
 * @size: Size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
				min_index = j;

		if (min_index != i)
		{
			swap(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}
