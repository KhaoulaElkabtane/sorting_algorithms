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
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return : Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, leng = size;
	bool b = false;

	if (array == NULL || size < 2)
		return;

	while (b == false)
	{
		b = true;
		for (i = 0; i < leng - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				b = false;
			}
		}
		leng--;
	}
}
