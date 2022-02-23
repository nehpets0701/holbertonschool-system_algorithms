#include "nary_trees.h"

/**
 * nary_tree_insert - insert new node
 * @parent: parent
 * @str: data
 * Return: new or NULL
*/
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->content = strdup(str);
	new->children = NULL;
	new->nb_children = 0;

	if (parent)
	{
		new->parent = parent;
		++parent->nb_children;
		new->next = parent->children;
		parent->children = new;
	}
	else
		new->next = new->parent = NULL;
	return (new);
}
