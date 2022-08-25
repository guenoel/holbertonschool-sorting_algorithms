#include "sort.h"
/**
 * swap_node - function to swap node
 * @node1: node to be swaped
 * @node2: other node
 *
 * Return: Nothing
 */

void swap_node(listint_t *node1, listint_t *node2)
{
	listint_t *tmpprev1;
	listint_t *tmpnext1;
	listint_t *tmpprev2;
	listint_t *tmpnext2;

	tmpprev1 = node1->prev;
	tmpnext1 = node1->next;
	tmpprev2 = node2->prev;
	tmpnext2 = node2->next;

	if (tmpprev1)
		tmpprev1->next = node2;

	if (node1->next == node2)
		node1->prev = node2;
	else
		node1->prev = tmpprev2;
	node1->next = tmpnext2;


	if (node2->prev == node1)
		node2->next = node1;
	else
		node2->next = tmpnext1;
	node2->prev = tmpprev1;

	if (tmpnext2)
		tmpnext2->prev = node1;
}

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
			cpt++;
			if (node->prev == NULL)
			{
				*list = node;
				node = node->next;
			}
			print_list(*list);
		}
	}
}
