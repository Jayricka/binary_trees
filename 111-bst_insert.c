#include "binary_trees.h"

/**
* bst_insert - Inserts a value in a Binary Search Tree (BST).
* @tree: A double pointer to the root node of the BST.
* @value: The value to insert.
* Return: A pointer to the created node, or NULL on failure.
*/
bst_t *bst_insert(bst_t **tree, int value)
{
if (!tree)
return (NULL);

/* If the tree is empty, create a new node as the root */
if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}

/* Traverse the tree to find the appropriate location for insertion */
if (value < (*tree)->n)
{
if ((*tree)->left == NULL)
{
(*tree)->left = binary_tree_node(*tree, value);
return ((*tree)->left);
}
else
return (bst_insert(&((*tree)->left), value));
}
else if (value > (*tree)->n)
{
if ((*tree)->right == NULL)
{
(*tree)->right = binary_tree_node(*tree, value);
return ((*tree)->right);
}
else
return (bst_insert(&((*tree)->right), value));
}

/* If the value is already in the tree, return NULL (no duplicates) */
return (NULL);
}

