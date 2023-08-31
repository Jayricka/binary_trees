#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_levelorder - Perform a level-order traversal on a binary tree.
* @tree: A pointer to the root node of the tree to traverse.
* @func: A pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
levelorder_queue_t *queue = NULL;

if (tree == NULL || func == NULL)
return;

enqueue(&queue, (binary_tree_t *)tree);

while (queue != NULL)
{
binary_tree_t *node = queue->node;

func(node->n);

if (node->left != NULL)
enqueue(&queue, node->left);
if (node->right != NULL)
enqueue(&queue, node->right);

dequeue(&queue);
}

free_queue(queue);
}

/**
* enqueue - Add a node to the end of a level-order traversal queue.
* @queue: A pointer to a pointer to the queue.
* @node: A pointer to the binary tree node to add to the queue.
*/
void enqueue(levelorder_queue_t **queue, binary_tree_t *node)
{
levelorder_queue_t *new_node, *last;

new_node = malloc(sizeof(levelorder_queue_t));
if (new_node == NULL)
return;

new_node->node = node;
new_node->next = NULL;

if (*queue == NULL)
{
*queue = new_node;
}
else
{
last = *queue;
while (last->next != NULL)
last = last->next;
last->next = new_node;
}
}

/**
* dequeue - Remove the front node from a level-order traversal queue.
* @queue: A pointer to a pointer to the queue.
*/
void dequeue(levelorder_queue_t **queue)
{
levelorder_queue_t *temp;

if (*queue == NULL)
return;

temp = *queue;
*queue = (*queue)->next;
free(temp);
}

/**
* free_queue - Free all nodes in a level-order traversal queue.
* @queue: A pointer to the queue.
*/
void free_queue(levelorder_queue_t *queue)
{
levelorder_queue_t *temp;

while (queue != NULL)
{
temp = queue;
queue = queue->next;
free(temp);
}
}
