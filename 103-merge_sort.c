#include "sort.h"

void mergeSubarr(int *sub, int *buffer, size_t frt, size_t m,
		size_t b);
void mergeSortRecursive(int *sub, int *buffer, size_t frt, size_t b);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Merge two subarrays into a single sorted array.
 * @sub: Pointer to the original array containing two subarrays.
 * @buffer: Temporary buffer to store the merged subarrays.
 * @frt: Index of the beginning of the first subarray.
 * @m: Index of the middle of the subarrays (end of the first subarray).
 * @b: Index of the end of the second subarray.
 * Rerun : Nothing.
 */
void mergeSubarr(int *sub, int *buffer, size_t frt, size_t m,
		size_t b)
{
	size_t i, j, r = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + frt, m - frt);

	printf("[right]: ");
	print_array(sub + m, b - m);

	for (i = frt, j = m; i < m && j < b; r++)
		buffer[r] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
	for (; i < m; i++)
		buffer[r++] = sub[i];
	for (; j < b; j++)
		buffer[r++] = sub[j];
	for (i = frt, r = 0; i < b; i++)
		sub[i] = buffer[r++];

	printf("[Done]: ");
	print_array(sub + frt, b - frt);
}

/**
 * mergeSortRecursive - Recursively sorts an array using
 * the merge sort algorithm.
 * @sub: Pointer to the array to be sorted.
 * @buffer: Temporary buffer used for merging.
 * @frt: Index of the first element in the array.
 * @b: Index of the last element in the array.
 * Return : Nothing.
 */
void mergeSortRecursive(int *sub, int *buffer, size_t frt, size_t b)
{
	size_t m;

	if (b - frt > 1)
	{
		m = frt + (b - frt) / 2;
		mergeSortRecursive(sub, buffer, frt, m);
		mergeSortRecursive(sub, buffer, m, b);
		mergeSubarr(sub, buffer, frt, m, b);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * Return : Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	mergeSortRecursive(array, buffer, 0, size);

	free(buffer);
}
