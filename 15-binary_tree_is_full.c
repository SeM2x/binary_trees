#include "binary_trees.h"

/**
 * _binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: number of leaves
 */
size_t _binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	return (_binary_tree_leaves(tree->left) + _binary_tree_leaves(tree->right));
}

/**
 * _binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: number of nodes
 */

size_t _binary_tree_nodes(const binary_tree_t *tree)
{
	return (_binary_tree_size(tree) - _binary_tree_leaves(tree));
}

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
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	return (_binary_tree_leaves(tree) == _binary_tree_nodes(tree) + 1);
}
