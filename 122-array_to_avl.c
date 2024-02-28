#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);

	return (tree);
}
