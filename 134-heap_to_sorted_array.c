#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to
 * a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Pointer to store the size of the array
 *
 * Return: Pointer to the sorted array (in descending order)
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t arr_size, i;
	int *sorted_array;

	if (!heap || !size)
		return (NULL);

	arr_size = binary_tree_size(heap);
	sorted_array = malloc(sizeof(int) * arr_size);

	if (!sorted_array)
		return (NULL);

	for (i = 0; i < arr_size; i++)
	{
		sorted_array[i] = heap->n;

		if (!heap->left && !heap->right)
			break;

		if (!heap->left || heap->left->n < heap->right->n)
		{
			heap->n = heap->right->n;
			heap = heap->right;
		}
		else
		{
			heap->n = heap->left->n;
			heap = heap->left;
		}
	}

	*size = arr_size;
	return (sorted_array);
}

