#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 4096);
    int front = 0, rear = 0;

    if (queue == NULL)
        return;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        const binary_tree_t *current = queue[front++];

        func(current->n);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }

    free(queue);
}
