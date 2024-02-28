#include "binary_trees.h"

/**
 * _binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree
 */
size_t _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + _binary_tree_size(tree->left) + _binary_tree_size(tree->right));
}

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
 * _pow - claculates base to the power of exponent
 *
 * @base: base
 * @exponent: exponent
 * Return: base to the power of exponent
 */
double _pow(double base, int exponent)
{
	double result = 1.0;
	int i;

	if (exponent >= 0)
	{
		for (i = 0; i < exponent; i++)
			result *= base;
	}
	else
	{
		for (i = 0; i > exponent; i--)
			result /= base;
	}

	return (result);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's full, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height;

	size = _binary_tree_size(tree);
	height = _binary_tree_height(tree);
	return (size == _pow(2, height + 1) - 1);
}
