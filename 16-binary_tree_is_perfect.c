#include "binary_trees.h"

/**
* binary_tree_height - Calculate the height of a binary tree
* @tree: Pointer to the root node of the tree
* Return: The height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (1 + (left_height > right_height ? left_height : right_height));
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree
* Return: 1 if perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

if (left_height == right_height)
{
if (tree->left == NULL && tree->right == NULL)
return (1);
return (binary_tree_is_perfect(tree->left) &&
	binary_tree_is_perfect(tree->right));
}

return (0);
}
