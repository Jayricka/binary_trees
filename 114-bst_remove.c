#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_find_min - Finds the minimum value node in a BST
 * @node: The root node of the BST
 *
 * Return: A pointer to the minimum value node
 */
bst_t *bst_find_min(bst_t *node)
{
    while (node->left)
        node = node->left;
    return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: A pointer to the new root node after removal, or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else {
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return (temp);
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return (temp);
        }
        bst_t *temp = bst_find_min(root->right);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }
    return (root);
}
