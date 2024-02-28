#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: a pointer to the root node of the tree.
 * @value: the value to remove in the tree
 * @return  a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *node, *min;

    node = bst_search(root, value);
    min = node->right;

    if (min)
    {
        while (min->left)
            min = min->left;
        min->parent->left = min->right;
        if (min->right)
            min->right->parent = min->parent;

        min->right = node->right;
        min->left = node->left;
        min->parent = node->parent;
    }
    else
    {
        min = node->left;
        if (min)
            min->parent = node->parent;
    }
    if (root == node)
        root = min;
    else if (node->parent->left == node)
        node->parent->left = min;
    else
        node->parent->right = min;

    free(node);
    return (root);
}
