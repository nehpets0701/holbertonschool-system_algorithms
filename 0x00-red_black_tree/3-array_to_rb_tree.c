#include "rb_trees.h"

/**
 * array_to_rb_tree-convert array to rb tree
 * @array:input
 * @size:size
 * Return: new tree
*/
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; ++i)
	{
		rb_tree_insert(&root, array[i]);
	}

	return (root);
}
