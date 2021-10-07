#include "rb_trees.h"

/**
 * rotate-rotates a tree
 * @tree:input
 * @node:node to rotate
 * @dir:direction of rotation
 */
void rotate(rb_tree_t **tree, rb_tree_t **node, int dir)
{
	rb_tree_t *new;
	rb_tree_t *p;

	if (!node || !*node)
		return;

	new = dir == LEFT_ROTATE ? (*node)->right : (*node)->left;
	if (!new)
		return;

	p = GET_PARENT(*node);
	dir == LEFT_ROTATE
		? ((*node)->right = new->left, new->left = (*node))
		: ((*node)->left = new->right, new->right = (*node));
	(*node)->parent = new;
	if (dir == LEFT_ROTATE ? (*node)->right : (*node)->left)
		dir == LEFT_ROTATE
			? ((*node)->right->parent = (*node))
			: ((*node)->left->parent = (*node));
	if (p)
	{
		if ((*node) == p->left)
			p->left = new;
		else if ((*node) == p->right)
			p->right = new;
	}
	else
		*tree = new;
	new->parent = p;
}

/**
*rb_tree_node-makes new node
*Return:pointer to node or NULL
*@parent:parent
*@value:value
*@color:color
*/
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new;

	new = malloc(sizeof(rb_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->color = color;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
