#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return (binary_tree_t *)(first);

	if (binary_tree_depth(first) < binary_tree_depth(second))
		return binary_trees_ancestor(first, second->parent);
	return binary_trees_ancestor(first->parent, second);
}