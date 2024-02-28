#include "binary_trees.h"
#include <limits.h>

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
 * binary_tree_node - creates a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Integer to be stored in the new node
 * Return: binary_tree_t*
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * _bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST to insert the value
 * @value:  the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure.
 */
bst_t *_bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	if (value > (*tree)->n)
		node = _bst_insert(&(*tree)->right, value);
	else if (value < (*tree)->n)
		node = _bst_insert(&(*tree)->left, value);
	else
		return (NULL);

	if (node && ((*tree)->left == node || (*tree)->right == node))
		node->parent = *tree;
	return (node);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 *
 * @tree: a double pointer to the root node of the AVL tree
 * for inserting the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL, *tmp = NULL;
	int balance = 0;

	node = _bst_insert(tree, value);
	if (node)
		tmp = node->parent;
	while (tmp != NULL)
	{
		balance = binary_tree_balance(tmp);

		if (balance > 1)
		{
			if (value < tmp->left->n)
				tmp = binary_tree_rotate_right(tmp);
			else
			{
				binary_tree_rotate_left(tmp->left);
				tmp = binary_tree_rotate_right(tmp);
			}
		}
		else if (balance < -1)
		{
			if (value > tmp->right->n)
				tmp = binary_tree_rotate_left(tmp);
			else
			{
				binary_tree_rotate_right(tmp->right);
				tmp = binary_tree_rotate_left(tmp);
			}
		}

		if (!tmp->parent)
			*tree = tmp;
		tmp = tmp->parent;
	}

	return (node);
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
    avl_insert(&root, INT_MIN);
    avl_insert(&root, INT_MAX);
    bst_remove(root, INT_MIN);
    bst_remove(root, INT_MAX);

    return (root);
}
