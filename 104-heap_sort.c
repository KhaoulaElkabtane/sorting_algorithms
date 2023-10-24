#include "sort.h"

void swap_ints(int *s, int *i);
void maxHeapify(int *array, size_t size, size_t bas, size_t rt);
void heap_sort(int *array, size_t size);

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
 * maxHeapify - Maintains the max-heap property in a binary heap.
 * @array: Pointer to the array representing the binary heap.
 * @size: Size of the array.
 * @bas: Size of the heap (number of elements to be considered).
 * @rt: Root index of the subtree to be heapified.
 * Return : Nothing.
 */
void maxHeapify(int *array, size_t size, size_t bas, size_t rt)
{
	size_t lef, rgh, lar;

	lef = 2 * rt + 1;
	rgh = 2 * rt + 2;
	lar = rt;

	if (lef < bas && array[lef] > array[lar])
		lar = lef;
	if (rgh < bas && array[rgh] > array[lar])
		lar = rgh;

	if (lar != rt)
	{
		swap_ints(array + rt, array + lar);
		print_array(array, size);
		maxHeapify(array, size, bas, lar);
	}
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return : Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		maxHeapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		maxHeapify(array, size, i, 0);
	}
}
