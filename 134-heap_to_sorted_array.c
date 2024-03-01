#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 * Return: the sorted array.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL, i = 0;

	if (!heap)
		return (NULL);

	while (heap)
	{
		array = realloc(array, (i + 1) * sizeof(int));
		array[i++] = heap_extract(&heap);
	}

	*size = i;

	return (array);
}
