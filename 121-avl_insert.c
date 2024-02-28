#include "binary_trees.h"

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
		node = (_bst_insert(&(*tree)->left, value));
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
				binary_tree_rotate_right(tmp);
			else
			{
				binary_tree_rotate_left(tmp->left);
				binary_tree_rotate_right(tmp);
			}
		}
		else if (balance < -1)
		{
			if (value > tmp->right->n)
				binary_tree_rotate_left(tmp);
			else
			{
				binary_tree_rotate_right(tmp->right);
				binary_tree_rotate_left(tmp);
			}
		}

		tmp = tmp->parent;
	}

	return (node);
}
