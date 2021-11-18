#include "graphs.h"

/**
*graph_create-creates a graph
*Return: pointer to graph
*/
graph_t *graph_create(void)
{
	graph_t *new;

	new = malloc(sizeof(graph_t));
	if (new == NULL)
		return (NULL);
	new->nb_vertices = 0;
	new->vertices = NULL;
	return (new);
}
