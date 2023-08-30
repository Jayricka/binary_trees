#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Create a queue to store nodes for level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 4096);  /* Adjust size as needed */
    if (queue == NULL)
        return;

    int front = 0, rear = 0;
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        /* Call the function with the value of the current node */
        func(current->n);

        /* Enqueue the left child if it exists */
        if (current->left)
            queue[rear++] = current->left;

        /* Enqueue the right child if it exists */
        if (current->right)
            queue[rear++] = current->right;
    }

    free(queue);
}
