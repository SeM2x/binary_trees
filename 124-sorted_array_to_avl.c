#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree, *node;

	if (size % 2 == 0 && size > 2)
	{
		tree = sorted_array_to_avl(array, size - 1);
		node = tree;
		while (node->right)
			node = node->right;
		node->right = binary_tree_node(node, array[size - 1]);
	}
	else
	{

		if (!size)
			return (NULL);

		if (size == 1)
			return (binary_tree_node(NULL, array[size / 2]));

		tree = binary_tree_node(NULL, array[size / 2]);

		node = sorted_array_to_avl(array, size / 2);
		tree->left = node;
		node->parent = tree;

		if (size / 2 + 1 < size)
		{
			node = sorted_array_to_avl(array + size / 2 + 1, size / 2);
			tree->right = node;
			node->parent = tree;
		}
	}
	return (tree);
}
