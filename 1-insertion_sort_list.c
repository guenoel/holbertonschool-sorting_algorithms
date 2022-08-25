#include "sort.h"

/**
 * insertion_sort_list - order with insertion sort
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list;
	listint_t *tmpswap;
	int cpt = 1;

	node = node->next;
	tmpswap = node;
	while (cpt)
	{
		cpt = 0;
		
		if (tmpswap->next)
			node = tmpswap;
		else
			break;

		while (node->n > node->prev->n)
		{
			node = node->next;
		}

		tmpswap = node->prev;
		while (node->prev->n > node->n)
		{
			swap_node(node->prev, node);
			print_list(*list);
			cpt++;
			if (node->prev == NULL)
				break;
			if (node->prev->prev == NULL)
				*list = node;
		}
	}
}
