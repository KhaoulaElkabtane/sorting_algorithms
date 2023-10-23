#include "sort.h"

void swap_ints(int *s, int *i);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: Pointer to the array to be partitioned.
 * @size: Number of elements in the array.
 * @let: Left index of the subarray to be partitioned.
 * @rgh: Right index of the subarray to be partitioned.
 *
 * Return: The final position of the pivot element after partitioning.
 */
int lomuto_partition(int *array, size_t size, int let, int rgh)
{
	int *p, a, b;

	p = array + rgh;
	for (a = b = let; b < rgh; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_ints(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *p)
	{
		swap_ints(array + a, p);
		print_array(array, size);
	}

	return (a);
}

/**
 * lomuto_sort - Sorts an array using the Lomuto partitioning and quicksort.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * @let: Left index of the subarray to be sorted.
 * @rgh: Right index of the subarray to be sorted.
 *
 * Return: No return value (void). The array is sorted in-place.
 */
void lomuto_sort(int *array, size_t size, int let, int rgh)
{
	int prt;

	if (rgh - let > 0)
	{
		prt = lomuto_partition(array, size, let, rgh);
		lomuto_sort(array, size, let, prt - 1);
		lomuto_sort(array, size, prt + 1, rgh);
	}
}

/**
 * quick_sort - Sorts an array using the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
