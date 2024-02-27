#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	binary_tree_t **stack, *node, *predecessor;
	int top = -1;

	if (!tree)
		return (0);

	stack = NULL;
	node = (binary_tree_t *)tree;
	predecessor = NULL;

	while (node || top > -1)
	{
		while (node)
		{
			stack = realloc(stack, (top + 2) * sizeof(binary_tree_t *));
			stack[++top] = node;
			node = node->left;
		}
		node = stack[top--];
		if (predecessor && node->n < predecessor->n)
			return (0);
		predecessor = node;
		node = node->right;
	}

	return (1);
}
