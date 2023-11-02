#include "binary_trees.h"

/**
 * bst_remove - Removes a node with a specific value
 * from a Binary Search Tree (BST).
 *
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			root = temp;
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			root = temp;
		}
		else
		{
			temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
