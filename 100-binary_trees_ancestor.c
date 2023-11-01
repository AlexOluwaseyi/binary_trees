#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 * If no common ancestor was found, return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth1 = 0, depth2 = 0;
	const binary_tree_t *temp1 = first, *temp2 = second;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	while (temp1)
	{
		temp1 = temp1->parent;
		depth1++;
	}

	while (temp2)
	{
		temp2 = temp2->parent;
		depth2++;
	}
	temp1 = first;
	temp2 = second;

	while (depth1 > depth2)
	{
		temp1 = temp1->parent;
		depth1--;
	}
	while (depth2 > depth1)
	{
		temp2 = temp2->parent;
		depth2--;
	}
	while (temp1 != temp2)
	{
		temp1 = temp1->parent;
		temp2 = temp2->parent;
	}
	return ((binary_tree_t *)temp1);
}
