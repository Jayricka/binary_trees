#include "binary_trees.h"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @first: Pointer to the first node
* @second: Pointer to the second node
* Return: Pointer to the lowest common ancestor node, or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
const binary_tree_t *ptr1 = first, *ptr2 = second;
size_t depth1 = 0, depth2 = 0;

if (!first || !second)
return (NULL);

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

ptr1 = first;
ptr2 = second;

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

while (ptr1 && ptr2 && ptr1 != ptr2)
{
ptr1 = ptr1->parent;
ptr2 = ptr2->parent;
}

return ((binary_tree_t *)ptr1);
}
