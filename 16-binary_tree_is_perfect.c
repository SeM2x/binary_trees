#include "binary_trees.h"
#include <math.h>

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's full, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (binary_tree_size(tree) == pow(2, binary_tree_height(tree)) - 1);
}
