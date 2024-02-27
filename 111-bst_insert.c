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
	bst_t *node;

	if (*tree == NULL)
	{
		node = malloc(sizeof(binary_tree_t));
		if (!node)
			return (NULL);
		node->n = value;
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		*tree = node;
		return (*tree);
	}

	if (value > (*tree)->n)
		node = bst_insert(&(*tree)->right, value);
	else if (value < (*tree)->n)
		node = (bst_insert(&(*tree)->left, value));
	else
		return (NULL);

	if (node && ((*tree)->left == node || (*tree)->right == node))
		node->parent = *tree;
	return (node);
}
