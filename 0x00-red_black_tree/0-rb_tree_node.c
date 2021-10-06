#include "rb_trees.h"

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

	new = malloc(sizeof(new)
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->color = color;
	new->left = NULL;
	new->right = NULL;
}
