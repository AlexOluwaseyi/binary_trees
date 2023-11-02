#include "binary_trees.h"

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
 * heapify - Maintain the Max Heap property after insertion.
 * @new_node: The newly inserted node.
 */
void heapify(heap_t *new_node)
{
	heap_t *temp;
	int value;

	temp = new_node;
	value = temp->n;

	while (temp->parent && value > temp->parent->n)
	{
		temp->n = temp->parent->n;
		temp->parent->n = value;
		temp = temp->parent;
	}
	new_node = temp;
}

/**
 * get_last_node - Get the last level-order node in the Max Binary Heap.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last level-order node.
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *last_node = root;

	while (last_node && last_node->left)
	{
		if (last_node->right)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}
	return (last_node);
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: A double pointer to the root of the heap.
 *
 * Return: The value stored in the root node.
 *         0 on failure or if the heap is empty.
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node;

	if (root == NULL || *root == NULL)
		return (0);

	extracted_value = (*root)->n;
	last_node = get_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	if (last_node->parent->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	(*root)->n = last_node->n;
	free(last_node);

	/* Rebuild the Max Heap if necessary */
	heapify(*root);

	return (extracted_value);
}
