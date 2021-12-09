#include "heap.h"

/**
*heap_create-creates a heap
*Return:new heap
*@data_cmp:comparison function
*/
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap;

	if (!data_cmp)
		return (NULL);
	heap = calloc(sizeof(*heap), 1);
	if (!heap)
		return (NULL);
	heap->data_cmp = data_cmp;
	return (heap);
}
