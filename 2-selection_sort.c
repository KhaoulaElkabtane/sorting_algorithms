#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers.
 * @s: Pointer to the first integer.
 * @i: Pointer to the second integer.
 * Return : Nothing.
 */
void swap_ints(int *s, int *i)
{
	int tm;

	tm = *s;
	*s = *i;
	*i = tm;
}

/**
 * selection_sort - Sorts an array of integers using
 * the selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * Return Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int *ara;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		ara = array + i;
		for (j = i + 1; j < size; j++)
			ara = (array[j] < *ara) ? (array + j) : ara;

		if ((array + i) != ara)
		{
			swap_ints(array + i, ara);
			print_array(array, size);
		}
	}
}
