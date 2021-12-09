#include "heap.h"

/**
 * getNodeN - get nth node
 * @node: input
 * @n: where to insert
 * Return: parent
 */
binary_tree_node_t *getNodeN(binary_tree_node_t *node, size_t n)
{
	int index = 0, mask;

	for (index = 0; 1 << (index + 1) <= (int)n; ++index)
		;
	for (--index; index >= 0; --index)
	{
		mask = 1 << index;
		if (n & mask)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * toHeap - makes node a heap
 * @heap: input
 * @node: inserted node
 * Return: current node
 */
binary_tree_node_t *toHeap(heap_t *heap, binary_tree_node_t *node)
{
	void *temp;

	if (!node || !node->parent)
		return (node);
	while (node->parent)
	{
		if (heap->data_cmp(node->parent->data, node->data) > 0)
		{
			temp = node->data;
			node->data = node->parent->data;
			node->parent->data = temp;
		}
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - insert into heap
 * @heap: input
 * @data: input
 * Return: new node
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node, *parent;

	if (!heap)
		return (NULL);
	node = binary_tree_node(NULL, data);
	if (!node)
		return (NULL);
	if (!heap->root)
	{
		heap->root = node;
	}
	else
	{
		parent = getNodeN(heap->root, heap->size + 1);
		if (!parent->left)
			parent->left = node;
		else
			parent->right = node;
		node->parent = parent;
	}
	heap->size += 1;
	return (toHeap(heap, node));
}
