#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree:  pointer to the root node of the tree to measure the height.
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, righ_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	if (left_height == 0 && tree->left)
		left_height = 1;
	righ_height = binary_tree_height(tree->right);
	if (righ_height == 0 && tree->right)
		righ_height = 1;

	return (left_height - righ_height);
}
