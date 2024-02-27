#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST to insert the value
 * @value:  the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	if (value > (*tree)->n)
		return (bst_insert(&(*tree)->right, value));
	else if (value < (*tree)->n)
		return (bst_insert(&(*tree)->left, value));

	return (NULL);
}