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

	if (binary_tree_is_root(tree) && binary_tree_is_leaf(tree))
		return (1);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_is_root - checks if a node is a root
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);
	return (1);
}