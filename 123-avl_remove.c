#include "binary_trees.h"

/**
 * _bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals to value.
 */
bst_t *_bst_search(const bst_t *tree, int value)
{

	if (!tree)
		return (NULL);

	if (tree->n < value)
		return (_bst_search(tree->right, value));
	if (tree->n > value)
		return (_bst_search(tree->left, value));

	return ((bst_t *)tree);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: a pointer to the root node of the tree.
 * @value: the value to remove in the tree
 * Return:  a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *min;

	node = _bst_search(root, value);
	if (!node)
		return (root);
	if (node->right)
	{
		min = node->right;
		while (min->left)
			min = min->left;
		if (min->parent != node)
			min->parent->left = min->right;
		else
			node->right = min->right;
		if (min->right)
			min->right->parent = min->parent;
		min->left = node->left;
		if (node->left)
			node->left->parent = min;
		min->right = node->right;
		if (node->right)
			node->right->parent = min;
		min->parent = node->parent;
	}
	else
	{
		min = node->left;
		if (min)
			min->parent = node->parent;
	}
	if (!node->parent)
		root = min;
	else if (node->parent->left == node)
		node->parent->left = min;
	else
		node->parent->right = min;

	free(node);
	return (root);
}

/**
 * avl_balance - balances a bst
 *
 * @root: a pointer to the root of the tree
 * Return: a pointer to the root of the balanced tree, or NULL.
 */
avl_t *avl_balance(avl_t *root)
{
	if (!root)
		return (NULL);

	root->left = avl_balance(root->left);
	root->right = avl_balance(root->right);

	if (binary_tree_balance(root) > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	else if (binary_tree_balance(root) < -1)
	{
		if (binary_tree_balance(root->left) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
/**
 * avl_remove - removes a node from an AVL tree
 *
 * @root: a pointer to the root node of the tree for removing a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree
 * after removing the desired value, and after rebalancing .
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = bst_remove(root, value);
	return (avl_balance(root));
}
