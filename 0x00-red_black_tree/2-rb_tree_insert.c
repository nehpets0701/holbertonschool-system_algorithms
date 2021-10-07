#include "rb_trees.h"

/**
 * right_side_fix-fix left if needed
 * @tree:input
 * @node:input
 * Return: new pointer
 */
rb_tree_t *right_side_fix(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *parent, *uncle, *gparent;

	parent = GET_PARENT(node);
	gparent = GET_GRANDPARENT(node);
	uncle = gparent->left;
	if (uncle && uncle->color == RED)
	{
		uncle->color = parent->color = BLACK;
		gparent->color = RED;
		node = gparent;
	}
	else
	{
		if (parent->left == node)
		{
			node = parent;
			rotate(tree, &node, RIGHT_ROTATE);
			parent = GET_PARENT(node);
			gparent = GET_GRANDPARENT(node);
		}
		parent->color = BLACK;
		if (gparent)
		{
			gparent->color = RED;
			rotate(tree, &gparent, LEFT_ROTATE);
		}
	}

	return (node);
}

/**
 * left_side_fix-fix left if needed
 * @tree:input
 * @node:input
 * Return: new pointer
 */
rb_tree_t *left_side_fix(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *parent, *uncle, *gparent;

	parent = GET_PARENT(node);
	gparent = GET_GRANDPARENT(node);
	uncle = gparent->right;
	if (uncle && uncle->color == RED)
	{
		uncle->color = parent->color = BLACK;
		gparent->color = RED;
		node = gparent;
	}
	else
	{
		if (parent->right == node)
		{
			node = parent;
			rotate(tree, &node, LEFT_ROTATE);
			parent = GET_PARENT(node);
			gparent = GET_GRANDPARENT(node);
		}
		parent->color = BLACK;
		if (gparent)
		{
			gparent->color = RED;
			rotate(tree, &gparent, RIGHT_ROTATE);
		}
	}

	return (node);
}

/**
 * rb_tree_fix-fix
 * @tree:input
 * @node:the new node
 */
void rb_tree_fix(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *parent = GET_PARENT(node), *gparent = GET_GRANDPARENT(node);

	while (parent && parent->color == RED)
	{
		if (gparent && gparent->left == parent)
			node = left_side_fix(tree, node);
		else
			node = right_side_fix(tree, node);

		parent = GET_PARENT(node);
		gparent = GET_GRANDPARENT(node);
	}
	(*tree)->color = BLACK;
}

/**
*rb_tree_insert-inserts a node
*Return: new node or null
*@tree:input
*@value:value
*/
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new = NULL, *current = NULL, *prev = NULL;

	if (!tree)
		return (NULL);
	current = *tree;
	while (current)
	{
		prev = current;
		if (current->n == value)
			return (NULL);
		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}
	new = rb_tree_node(NULL, value, RED);
	if (!new)
		return (NULL);
	new->parent = prev;
	if (!prev)
		*tree = new;
	else if (new->n < prev->n)
		prev->left = new;
	else
		prev->right = new;
	rb_tree_fix(tree, new);
	return (new);
}
