#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * max_heapify - ensures the Max Heap property is maintained
 * @root: pointer to the root of the binary heap
 */
void max_heapify(heap_t *root)
{
	int value;
	heap_t *largest, *left, *right;

	if (!root)
		return;

	largest = root;
	left = root->left;
	right = root->right;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		value = root->n;
		root->n = largest->n;
		largest->n = value;
		max_heapify(largest);
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of the extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_root, *last_node;

	if (!root || !*root)
		return (0);

	heap_root = *root;
	value = heap_root->n;

	if (!heap_root->left && !heap_root->right)
	{
		free(heap_root);
		*root = NULL;
		return (value);
	}

	last_node = *root;
	while (last_node->left)
	{
		if (!last_node->left->left || !last_node->left->right)
			break;
		last_node = last_node->left;
	}

	if (last_node->right)
	{
		heap_root->n = last_node->right->n;
		free(last_node->right);
		last_node->right = NULL;
	}
	else
	{
		heap_root->n = last_node->left->n;
		free(last_node->left);
		last_node->left = NULL;
	}

	max_heapify(heap_root);
	return (value);
}
