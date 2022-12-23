#include "binary_trees.h"

/**
 * heap_insert - insert a node into the max heap.
 * @root: the root node.
 * @value: the value to insert.
 * Return: the node inserted or null.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL;

	if (!root)
		return (NULL);

	node = malloc(sizeof(heap_t));

	if (!node)
		return (NULL);

	node = binary_tree_node(*root, value);

	if (!*root)
	{
		*root = node;
		return (node);
	}

	return (node);
}
