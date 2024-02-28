#include "binary_trees.h"

/**
 * _binary_tree_height - measures the height of a binary tree
 *
 * @tree:  pointer to the root node of the tree to measure the height.
 * Return: the height of the tree
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + _binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + _binary_tree_height(tree->right);

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
	int left_height = 0, right_height = 0;
	binary_tree_t *node = (binary_tree_t *)tree, *tmp;

	if (!tree)
		return (0);

	tmp = node->right;
	node->right = NULL;
	left_height = _binary_tree_height(tree);

	node->right = tmp;
	tmp = node->left;
	node->left = NULL;
	right_height = _binary_tree_height(tree);

	node->left = tmp;
	tmp = NULL;
	node = NULL;

	return (left_height - right_height);
}
