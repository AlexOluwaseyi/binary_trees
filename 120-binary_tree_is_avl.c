#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_util - Helper function to check if a binary tree is a valid BST.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @min: The minimum valid value for this subtree.
 * @max: The maximum valid value for this subtree.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n) &&
			is_bst_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is
 * a valid Binary Search Tree (BST).
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 * If tree is NULL, return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the binary tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height, padding = 0;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		padding = 1;

	return ((left_height > right_height) ?
			(left_height + padding) : (right_height + padding));
}

/**
 * is_valid_avl - Recursive helper function to check
 * if a binary tree is a valid AVL tree.
 *
 * @tree: Pointer to the current node.
 * @min: Minimum value allowed for the node (for subtree validation).
 * @max: Maximum value allowed for the node (for subtree validation).
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int is_valid_avl(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, balance;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	balance = left_height - right_height;

	if (balance > 1 || balance < -1)
		return (0);

	return (is_valid_avl(tree->left, min, tree->n) &&
			is_valid_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 * If tree is NULL, return 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_avl(tree, INT_MIN, INT_MAX)
			&& binary_tree_is_bst(tree));
}
