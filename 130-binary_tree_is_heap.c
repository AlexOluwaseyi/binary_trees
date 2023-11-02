#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the binary tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
	{
		return (0);
	}

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}

/**
 * is_complete - Check if the binary tree is complete.
 * @tree: A pointer to the root node of the tree.
 * @index: The index of the current node.
 * @node_count: The number of nodes in the tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
			is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * is_max_heap - Check if the binary tree is a max heap.
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count = 0;

	if (tree == NULL)
		return (0);

	node_count = binary_tree_size(tree);

	return (is_complete(tree, 0, node_count) && is_max_heap(tree));
}
