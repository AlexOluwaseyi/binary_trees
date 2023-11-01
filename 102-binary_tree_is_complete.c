#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 if not.
 * If tree is NULL, the function returns 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *current;
	size_t front = 0, rear = 0, last_level = 0, is_last_level = 1, i;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		last_level = rear;
		if (current->left)
		{
			if (is_last_level == 0)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
		} else
			is_last_level = 0;
		if (current->right)
		{
			if (is_last_level == 0)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->right;
		} else
			is_last_level = 0;
	}
	for (i = last_level; i < rear; i++)
	{
		if (queue[i]->left || queue[i]->right)
		{
			free(queue);
			return (0);
		}
	}
	free(queue);
	return (1);
}
