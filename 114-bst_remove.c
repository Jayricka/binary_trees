#include "binary_trees.h"
#include <stdlib.h>

/**
 * inorder_successor - Returns the minimum value node in a BST.
 * @node: A pointer to the node to start the search from.
 *
 * Return: A pointer to the minimum value node.
 */
bst_t *inorder_successor(bst_t *node)
{
    while (node->left)
        node = node->left;
    return node;
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
    if (!root || !node)
        return root;

    if (node->n < root->n)
        root->left = bst_delete(root->left, node);
    else if (node->n > root->n)
        root->right = bst_delete(root->right, node);
    else {
        if (!root->left) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        bst_t *temp = inorder_successor(root->right);
        root->n = temp->n;
        root->right = bst_delete(root->right, temp);
    }

    return root;
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
    if (!root)
        return root;

    if (value < root->n)
        root->left = bst_remove_recursive(root->left, node, value);
    else if (value > root->n)
        root->right = bst_remove_recursive(root->right, node, value);
    else {
        if (root == node)
            return bst_delete(root, node);
    }

    return root;
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return bst_remove_recursive(root, root, value);
}
