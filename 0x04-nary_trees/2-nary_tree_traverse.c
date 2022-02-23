#include "nary_trees.h"

/**
* ntree_traverse - traverse tree
* @root: tree
* @action: action
* @depth: current depth
* Return: max depth
*/
size_t ntree_traverse(nary_tree_t const *root, void
					  (*action)(nary_tree_t const *node, size_t depth),
					  size_t depth)
{
	nary_tree_t const *node;
	size_t max = 0, ret;

	if (!root)
		return (0);
	node = root;
	while (node)
	{
		action(node, depth);
		ret = ntree_traverse(node->children, action, depth + 1);
		if (max < ret)
			max = ret;
		node = node->next;
	}
	return (1 + max);
}

/**
* nary_tree_traverse - traverse nary tree
* @root: tree
* @action: action
* Return: maximum depth
*/
size_t nary_tree_traverse(nary_tree_t const *root,
						  void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t depth;

	if (!root || !action)
		return (0);
	depth = ntree_traverse(root, action, 0);
	return (depth);
}
