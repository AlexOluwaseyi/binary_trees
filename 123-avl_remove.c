#include "binary_trees.h"

/**
 * avl_remove - Removes a node with a specific value from an AVL tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the value.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			avl_t *temp = (root->left) ? root->left : root->right;
			free(root);
			return temp;
		}
		else
		{
			avl_t *temp = root->right;
			while (temp->left)
				temp = temp->left;
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	int balance = binary_tree_balance(root);
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return binary_tree_rotate_right(root);
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return binary_tree_rotate_left(root);
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return binary_tree_rotate_right(root);
	}
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return binary_tree_rotate_left(root);
	}
	return root;
}
