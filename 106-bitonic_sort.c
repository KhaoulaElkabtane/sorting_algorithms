#include "sort.h"

void swap_ints(int *s, int *i);
void bitonicMerge(int *array, size_t size, size_t str, size_t s,
		char flw);
void bitonicSeq(int *array, size_t size, size_t str, size_t s, char flw);
void bitonic_sort(int *array, size_t size);

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
 * bitonicMerge - Merges two subsequences in ascending or descending order.
 * @array: Pointer to the array to be merged.
 * @size: Size of the array.
 * @str: Starting index of the first subsequence.
 * @s: Step size used for merging.
 * @flw: Order of merging (UP for ascending, DOWN for descending).
 * Return : Nothing.
 */
void bitonicMerge(int *array, size_t size, size_t str, size_t s,
		char flw)
{
	size_t i, jump = s / 2;

	if (s > 1)
	{
		for (i = str; i < str + jump; i++)
		{
			if ((flw == UP && array[i] > array[i + jump]) ||
			    (flw == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonicMerge(array, size, str, jump, flw);
		bitonicMerge(array, size, str + jump, jump, flw);
	}
}

/**
 * bitonicSeq - Sorts an array using the Bitonic Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @str: Starting index of the current subsequence.
 * @s: Step size used for sorting.
 * @flw: Order of sorting (UP for ascending, DOWN for descending).
 * Return : Nothing.
 */
void bitonicSeq(int *array, size_t size, size_t str, size_t s, char flw)
{
	size_t cut = s / 2;
	char *sr = (flw == UP) ? "UP" : "DOWN";

	if (s > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", s, size, sr);
		print_array(array + str, s);

		bitonicSeq(array, size, str, cut, UP);
		bitonicSeq(array, size, str + cut, cut, DOWN);
		bitonicMerge(array, size, str, s, flw);

		printf("Result [%lu/%lu] (%s):\n", s, size, sr);
		print_array(array + str, s);
	}
}

/**
 * bitonic_sort - Sorts an array in ascending order using Bitonic Sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Rerutn : Nothing.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonicSeq(array, size, 0, size, UP);
}
