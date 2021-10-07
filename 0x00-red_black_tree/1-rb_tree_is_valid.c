#include "rb_trees.h"

/**
* helper-recursive helper
* @n:level
* @tree:node
* Return:-1/height
*/
int helper(int n, const rb_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (n);

	if (tree->color != BLACK && tree->color != RED)
		return (-1);

	if (tree->color == RED && tree->parent->color == RED)
		return (-1);

	if (tree->color == BLACK)
		n++;

	height = helper(n, tree->left);
	if (height != helper(n, tree->right))
		return (-1);

	return (height);
}

/**
*rb_tree_is_valid-tells if a tree is valid
*Return:0/1
*@tree:input
*/
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->color != BLACK)
		return (0);

	if (helper(0, tree) == -1)
		return (0);

	return (1);
}
