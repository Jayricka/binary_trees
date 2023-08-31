#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_successor - Finds the in-order successor of a node in a BST
 * @node: A pointer to the node for which to find the successor
 *
 * Return: A pointer to the in-order successor node, or NULL if not found
 */
bst_t *find_successor(bst_t *node)
{
	if (!node)
		return (NULL);

	if (node->right)
	{
		node = node->right;
		while (node->left)
			node = node->left;
		return (node);

	}

	while (node->parent && node->parent->right == node)
		node = node->parent;

	return (node->parent);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to be removed from the tree
 *
 * Return: Pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			bst_t *temp = root->right;

			free(root);

			return (temp);
		}
		else if (!root->right)
		{
			bst_t *temp = root->left;

			free(root);

			return (temp);

		}

		bst_t *temp = find_successor(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
