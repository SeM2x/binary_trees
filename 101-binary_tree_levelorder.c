#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *node;
	int front = 0, rear = 0;

	if (!tree || !func)
		return;

	queue = malloc(sizeof(binary_tree_t *));
	*queue = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		node = queue[front++];
		func(node->n);

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
}
