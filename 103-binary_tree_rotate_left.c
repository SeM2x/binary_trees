#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	x = tree;
	y = tree->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (!x->parent)
		tree = y;
	else if (x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;

	x->parent = y;
	y->left = x;

	return (y);
}
