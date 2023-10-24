#include "sort.h"

int getMax(int *ara, int size);
void radixCountingSort(int *array, size_t size, int s, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * getMax - Finds the maximum element in an integer array.
 * @array: Pointer to the integer array.
 * @size: Size of the array.
 *
 * Return: The maximum value in the array.
 */
int getMax(int *ara, int size)
{
	int m, i;

	for (m = array[0], i = 1; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}

	return (m);
}

/**
* radixCountingSort - Counting sort for Radix Sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @s: The current significant digit to sort on.
 * @buffer: Temporary buffer for sorting.
 * Return : Nothing
 */
void radixCountingSort(int *array, size_t size, int s, int *buffer)
{
	int coun[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		coun[(array[i] / s) % 10] += 1;

	for (i = 0; i < 10; i++)
		coun[i] += coun[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[coun[(array[i] / s) % 10] - 1] = array[i];
		coun[(array[i] / s) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sorts an array of integers using Radix Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return : Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int m, s, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	m = getMax(array, size);
	for (s = 1; m / s > 0; s *= 10)
	{
		radixCountingSort(array, size, s, buffer);
		print_array(array, size);
	}

	free(buffer);
}
