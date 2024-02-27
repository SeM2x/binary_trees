#include "binary_trees.h"

/**
 * binary_tree_is_bst_helper - helper function to binary_tree_is_bst
 *
 * @node: pointer to the root node
 * @min: min value of the tree
 * @max: max value of the tree
 * Return: 0 or 1.
 */
int binary_tree_is_bst_helper(const binary_tree_t *node, const binary_tree_t *min, const binary_tree_t *max)
{
	if (!node)
		return 1;

	if ((min && node->n <= min->n) || (max && node->n >= max->n))
		return 0;

	return (binary_tree_is_bst_helper(node->left, min, node) &&
			binary_tree_is_bst_helper(node->right, node, max));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return binary_tree_is_bst_helper(tree, NULL, NULL);
}
