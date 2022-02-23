#include "nary_trees.h"

/**
* path_exists - check if path exists
* @root: tree
* @path: input
* Return: 0/1
*/
int path_exists(nary_tree_t const *root, char const * const *path)
{
	int i = 0;
	nary_tree_t const *node;

	if (!root || !path || !path[i])
		return (0);
	node = root;
	while (node)
	{
		while (node && strcmp(path[i], node->content))
			node = node->next;
		if (!node)
			return (0);
		node = node->children;
		++i;
		if (!path[i])
			break;
	}

	return (!path[i]);
}
