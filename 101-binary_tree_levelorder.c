#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Perform level-order traversal on a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: This function traverses the binary tree using level-order
 * (breadth-first) traversal and applies the given function to each node's
 * value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Create a queue for level-order traversal */
    const binary_tree_t *current;
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 4096);
    size_t front = 0, rear = 0;

    if (queue == NULL)
        return;

    /* Initialize the queue and enqueue the root node */
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        current = queue[front++];
        func(current->n);

        /* Enqueue the left child (if exists) */
        if (current->left != NULL)
            queue[rear++] = current->left;

        /* Enqueue the right child (if exists) */
        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    free(queue);
}
