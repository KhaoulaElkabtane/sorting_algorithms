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
 * shell_sort - Sorts an array using the Shell Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * Return : Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t str, i, j;

	if (array == NULL || size < 2)
		return;

	for (str = 1; str < (size / 3);)
		str = str * 3 + 1;

	for (; str >= 1; str /= 3)
	{
		for (i = str; i < size; i++)
		{
			j = i;
			while (j >= str && array[j - str] > array[j])
			{
				swap_ints(array + j, array + (j - str));
				j -= str;
			}
		}
		print_array(array, size);
	}
}
