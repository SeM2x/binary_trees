#include "binary_trees.h"

/**
 * swap_nodes - Swaps values between two nodes
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_down - Adjusts a node's place in the heap tree
 * @root: A pointer to the root node of the heap
 * @node: A pointer to the node to start the heapify operation
 */
void heapify_down(heap_t *root, heap_t *node)
{
	heap_t *largest = node;
	heap_t *left_child = node->left;
	heap_t *right_child = node->right;

	if (left_child && left_child->n > largest->n)
		largest = left_child;

	if (right_child && right_child->n > largest->n)
		largest = right_child;

	if (largest != node)
	{
		swap_nodes(node, largest);
		heapify_down(root, largest);
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 *
 * @root: a double pointer to the root node of heap
 * @return the value stored in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t **queue, *node;
	int front = 0, rear = 0, value = 0;

	if (!*root)
		return (0);

	value = (*root)->n;
	queue = malloc(sizeof(heap_t *));
	*queue = *root;
	rear++;
	while (front < rear)
	{
		node = queue[front++];

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

	node->left = (*root)->left;
	if (node->left)
		node->left->parent = node;
	node->right = (*root)->right;
	if (node->right)
		node->right->parent = node;
	if (node->parent && node->parent->left == node)
		node->parent->left = NULL;
	else if (node->parent && node->parent->right == node)
		node->parent->right = NULL;
	node->parent = NULL;
	free(*root);
	*root = node;
	heapify_down(*root, node);
	return (value);
}
