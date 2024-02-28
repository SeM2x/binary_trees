#include "binary_trees.h"

/**
 * _binary_tree_height_ - measures the height of a binary tree
 *
 * @tree:  pointer to the root node of the tree to measure the height.
 * Return: the height of the tree
 */
size_t _binary_tree_height_(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + _binary_tree_height_(tree->left);
	if (tree->right)
		right_height = 1 + _binary_tree_height_(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * _binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: the balance factor
 */
int _binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;
	binary_tree_t *node = (binary_tree_t *)tree, *tmp;

	if (!tree)
		return (0);

	tmp = node->right;
	node->right = NULL;
	left_height = _binary_tree_height_(tree);

	node->right = tmp;
	tmp = node->left;
	node->left = NULL;
	right_height = _binary_tree_height_(tree);

	node->left = tmp;
	tmp = NULL;
	node = NULL;

	return (left_height - right_height);
}

/**
 * _binary_tree_is_bst_helper - _binary_tree_is_bst helper function
 *
 * @node: pointer to the root node
 * @min: min value of the tree
 * @max: max value of the tree
 * Return: 0 or 1.
 */
int _binary_tree_is_bst_helper(const binary_tree_t *node,
							   const binary_tree_t *min,
							   const binary_tree_t *max)
{
	if (!node)
		return (1);

	if ((min && node->n <= min->n) || (max && node->n >= max->n))
		return (0);

	return (_binary_tree_is_bst_helper(node->left, min, node) &&
			_binary_tree_is_bst_helper(node->right, node, max));
}
/**
 * _binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int _binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_is_bst_helper(tree, NULL, NULL));
}
/**
 *  binary_tree_is_avl_helper - binary_tree_is_avl helper function
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is balanced, and 0 otherwise.
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	int balance = _binary_tree_balance(tree);

	if (!tree)
		return (1);

	if (balance > 1 || balance < -1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left) &&
			binary_tree_is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (_binary_tree_is_bst(tree))
		return (binary_tree_is_avl_helper(tree));

	return (0);
}
