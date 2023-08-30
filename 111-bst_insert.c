#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: A double pointer to the root node of the BST
 * @value: The value to insert
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current;

    if (tree == NULL)
        return (NULL);

    /* Create a new node */
    new_node = binary_tree_node(NULL, value);

    if (new_node == NULL)
        return (NULL);

    /* If the tree is empty, make the new node the root */
    if (*tree == NULL)
    {
        *tree = new_node;
        return (new_node);
    }

    /* Traverse the tree to find the correct position to insert */
    current = *tree;
    while (current)
    {
        if (value == current->n)
        {
            free(new_node);
            return (NULL); /* Value already exists, ignore */
        }
        if (value < current->n)
        {
            if (current->left == NULL)
            {
                new_node->parent = current;
                current->left = new_node;
                return (new_node);
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                new_node->parent = current;
                current->right = new_node;
                return (new_node);
            }
            current = current->right;
        }
    }

    return (NULL); /* Should not reach here */
}
