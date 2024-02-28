#include "binary_trees.h"

/**
 * @brief 
 * 
 * @param root 
 * @return avl_t* 
 */
avl_t *avl_balance(avl_t *root)
{
    if (!root)
        return (NULL);

    root->left = avl_balance(root->left);
    root->right = avl_balance(root->right);

    if (binary_tree_balance(root)> 1)
    {
        if (binary_tree_balance(root->left) < 0)
            root->left = binary_tree_rotate_left(root->left);
        return (binary_tree_rotate_right(root));
    }
    else if (binary_tree_balance(root) < -1)
    {
        if (binary_tree_balance(root->left) > 0)
            root->right = binary_tree_rotate_right(root->right);
        return (binary_tree_rotate_left(root));
	}

    return (root);
}
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
    return (avl_balance(root));
}
