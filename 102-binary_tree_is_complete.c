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

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_depth -  measures the depth of a node in a binary tree
 *
 * @tree: pointer to the node to measure the depth
 * Return: the depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *node;
	int front = 0, rear = 0, right_empty = 0;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *));
	*queue = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		node = queue[front++];

		if ((right_empty && node->left) || (!node->left && node->right))
			return (0);

		if (node->left && !node->right)
			right_empty = 1;

		if (node->left)
		{
			queue = realloc(queue, (rear + 1) * sizeof(binary_tree_t *));
			queue[rear++] = node->left;
		}
		if (node->right)
		{
			queue = realloc(queue, (rear + 1) * sizeof(binary_tree_t *));
			queue[rear++] = node->right;
		}
	}

	free(queue);

	return (1);
}
