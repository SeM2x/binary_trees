#include "binary_trees.h"

/**
 * binary_tree_t - creates a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Integer to be stored in the new node
 * Return: binary_tree_t*
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node;

    node = malloc(sizeof(binary_tree_t));
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
}