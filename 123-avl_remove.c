#include "binary_trees.h"
#include <limits.h>

/**
 * avl_remove - removes a node from an AVL tree
 * 
 * @root: a pointer to the root node of the tree for removing a node 
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree
 * after removing the desired value, and after rebalancing .
 */
avl_t *avl_remove(avl_t *root, int value)
{
    root = bst_remove(root, value);
    avl_insert(&root, INT_MIN);
    avl_insert(&root, INT_MAX);
    bst_remove(root, INT_MIN);
    bst_remove(root, INT_MAX);
    
    return (root);
}
