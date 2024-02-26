#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	return (binary_tree_leaves(tree) == binary_tree_nodes(tree) + 1);
}
