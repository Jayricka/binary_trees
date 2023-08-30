#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Create a queue to perform level-order traversal */
	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 4096); /* Adjust size as needed */
	if (queue == NULL)
		return (0);

	int front = 0, rear = 0;
	int missing_node = 0; /* Flag to track if a missing node is encountered */

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		/* If a missing node is encountered, all nodes after it must be leaves */
		if (current == NULL)
			missing_node = 1;
		else
		{
			if (missing_node)
				return (0); /* Not complete if a non-leaf node comes after a missing node */

			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	/* If we reach here, the tree is complete */
	free(queue);
	return (1);
}
