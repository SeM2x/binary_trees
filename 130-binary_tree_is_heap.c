#include "binary_trees.h"

/**
 * _binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int _binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *node;
	int front = 0, rear = 0, end_of_level = 0;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *));
	*queue = (binary_tree_t *)tree;
	rear++;
	while (front < rear)
	{
		node = queue[front++];
		if (!node->left)
			end_of_level = 1;
		if (end_of_level && (node->left || node->right))
		{
			free(queue);
			return (0);
		}
		if (!node->right)
			end_of_level = 1;

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
/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_heap = 1;

	if (!tree)
		return (0);

	is_heap *= _binary_tree_is_complete(tree);

	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);

	if (tree->left)
		is_heap *= binary_tree_is_heap(tree->left);
	if (tree->right)
		is_heap *= binary_tree_is_heap(tree->right);

	return (is_heap);
}
