#include "binary_trees.h"

/**
 * heapify_up - adjusts a node's place in the heap tree
 *
 * @node: a pointer to the node
 * Return: a pointer to the adjusted node.
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node && node->parent)
	{
		if (node->n > node->parent->n)
		{
			temp = node->n;
			node->n = node->parent->n;
			node->parent->n = temp;
			node = node->parent;
		}
		else
			break;
	}
	return (node);
}
/**
 * heap_insert - inserts a value in Max Binary Heap
 *
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 * @return return a pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t **queue, *node;
	int front = 0, rear = 0;

	if (!*root)
	{
		*root = (binary_tree_node(NULL, value));
		return (*root);
	}
	queue = malloc(sizeof(heap_t *));
	*queue = *root;
	rear++;
	while (front < rear)
	{
		node = queue[front++];
		if (!node->left)
		{
			node->left = binary_tree_node(node, value);
			node = node->left;
			break;
		}
		else if (!node->right)
		{
			node->right = binary_tree_node(node, value);
			node = node->right;
			break;
		}
		if (node->left)
		{
			queue = realloc(queue, (rear + 1) * sizeof(heap_t *));
			queue[rear++] = node->left;
		}
		if (node->right)
		{
			queue = realloc(queue, (rear + 1) * sizeof(heap_t *));
			queue[rear++] = node->right;
		}
	}
	free(queue);
	return heapify_up(node);
}
