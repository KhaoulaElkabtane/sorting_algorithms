#include "sort.h"

/**
 * getMax - Find the maximum value in an array of integers.
 * @ara: Pointer to an array of integers.
 * @size: Number of elements in the array.
 *
 * Return: The maximum value in the array.
 */
int getMax(int *ara, int size)
{
	int max, i;

	for (max = ara[0], i = 1; i < size; i++)
	{
		if (ara[i] > max)
			max = ara[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers using counting sort.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * Return : Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *cout, *ted, max, i;

	if (array == NULL || size < 2)
		return;

	ted = malloc(sizeof(int) * size);
	if (ted == NULL)
		return;
	max = getMax(array, size);
	cout = malloc(sizeof(int) * (max + 1));
	if (cout == NULL)
	{
		free(ted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		cout[i] = 0;
	for (i = 0; i < (int)size; i++)
		cout[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		cout[i] += cout[i - 1];
	print_array(cout, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		ted[cout[array[i]] - 1] = array[i];
		cout[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = ted[i];

	free(ted);
	free(cout);
}
