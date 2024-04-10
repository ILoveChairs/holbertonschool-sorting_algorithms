#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _intercambiador - Exchanger.
 *
 * @array: Array.
 * @size: Size of array.
 *
 * @pivot: Index of pivot.
 * @i: i.
 */
void _intercambiador(int *array, size_t size, size_t pivot, size_t i)
{
	int tmp;

	if (pivot - 1 == i)
	{
		tmp = array[pivot];
		array[pivot] = array[i];
		array[i] = tmp;
		return;
	}

	tmp = array[pivot - 1];

	array[pivot - 1] = array[pivot];
	array[pivot] = array[i];
	array[i] = tmp;

	size += 1;
}

/**
 * _quick_sort_recursive - Recursive function.
 *
 * @array: Array.
 * @size: Size.
 *
 * @start: asdfg
 * @end: asdfg
 */
void _quick_sort_recursive(int *array, size_t size, size_t start, size_t end)
{
	size_t pivot;
	size_t i;

	if (end - start < 2)
		return;

	pivot = end;

	i = start;
	while (i < pivot)
	{
		if (pivot == start + 1)
		{
			if (array[start] > array[pivot])
				_intercambiador(array, size, pivot, i);
			break;
		}

		if (array[i] < array[pivot])
			i += 1;
		else
			_intercambiador(array, size, pivot--, i);
	}

	print_array(array, size);

	_quick_sort_recursive(array, size, start, pivot - 1);
	_quick_sort_recursive(array, size, pivot, end);
}


/**
 * quick_sort - Quick sorts array.
 *
 * @array: Array to sort.
 *
 * @size: Size of array.
 */
void quick_sort(int *array, size_t size)
{
	_quick_sort_recursive(array, size, 0, size - 1);
}



