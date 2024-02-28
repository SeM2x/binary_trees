#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (!tree || !tree->left)
		return (NULL);

	x = tree;
	y = tree->left;
	x->left = y->right;
	if (y->right)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent)
	{
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	x->parent = y;
	y->right = x;

	return (y);
}
