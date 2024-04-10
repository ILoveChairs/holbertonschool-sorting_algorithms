#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - swaps two integers in an array.
 * @array: The array to sort.
 * @i: The first index to swap.
 * @j: The second index to swap.
 * @size: The size of the array.
 */
void swap(int *array, int i, int j, size_t size)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * partition - orders a subset of an array of integers according to
 * the Lomuto scheme.
 * @array: The array to sort.
 * @lo: The lowest index of the subset to order.
 * @hi: The highest index of the subset to order.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, above, below;

	pivot = array[hi];
	for (above = lo, below = lo; below < hi; below++)
	{
		if (array[below] < pivot)
		{
			if (above < below)
				swap(array, above, below, size);
			above++;
		}
	}
	if (array[hi] < array[above])
		swap(array, above, hi, size);
	return (above);
}

/**
 * quick_sort_rec - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: The array to sort.
 * @lo: The lowest index of the array to sort.
 * @hi: The highest index of the array to sort.
 * @size: The size of the array.
 */
void quick_sort_rec(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_rec(array, lo, p - 1, size);
		quick_sort_rec(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
