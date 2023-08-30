#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ptr1, *ptr2;
	size_t depth1 = 0, depth2 = 0;

	if (!first || !second)
		return (NULL);

	ptr1 = first;
	ptr2 = second;

	/* Calculate the depth of each node */
	while (ptr1)
	{
		ptr1 = ptr1->parent;
		depth1++;
	}

	while (ptr2)
	{
		ptr2 = ptr2->parent;
		depth2++;
	}

	/* Reset pointers to the original nodes */
	ptr1 = first;
	ptr2 = second;

	/* Move the deeper node up to the same depth as the other node */
	while (depth1 > depth2)
	{
		ptr1 = ptr1->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		ptr2 = ptr2->parent;
		depth2--;
	}

	/* Move both nodes up in tandem until the common ancestor is found */
	while (ptr1 && ptr2 && ptr1 != ptr2)
	{
		ptr1 = ptr1->parent;
		ptr2 = ptr2->parent;
	}

	return ((binary_tree_t *)ptr1);
}
