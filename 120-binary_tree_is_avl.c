#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>

/**
* binary_tree_height - Calculate the height of a binary tree
* @tree: Pointer to the root node of the tree
* Return: The height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

size_t left_height = binary_tree_height(tree->left);
size_t right_height = binary_tree_height(tree->right);

return (1 + (left_height > right_height ? left_height : right_height));
}

/**
* is_avl_util - Utility function to check if a binary tree is a valid AVL tree
* @tree: Pointer to the root node of the tree to check
* @min: Minimum allowed value in the tree
* @max: Maximum allowed value in the tree
* Return: 1 if tree is a valid AVL Tree, 0 otherwise
*/
int is_avl_util(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);

if (tree->n <= min || tree->n >= max)
return (0);

int left_height = binary_tree_height(tree->left);
int right_height = binary_tree_height(tree->right);

if (abs(left_height - right_height) > 1)
return (0);

return (is_avl_util(tree->left, min, tree->n) &&
is_avl_util(tree->right, tree->n, max));
}

/**
* binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
* @tree: Pointer to the root node of the tree to check
* Return: 1 if tree is a valid AVL Tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (is_avl_util(tree, INT_MIN, INT_MAX));
}
