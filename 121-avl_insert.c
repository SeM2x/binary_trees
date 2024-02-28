#include "binary_trees.h"

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

	node = bst_insert(tree, value);
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
