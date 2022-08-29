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
 * cocktail_sort_list - sort list cocktail method
 * @list: list
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node;

	int cpt = 1;

	node = *list;
	/*si pas de liste ou 1 seule node dans la liste*/
	if (node == NULL || node->next == NULL)
		return;

	while (cpt)
	{
		cpt = 0;

		while (node->next)
		{
			if (node->n > node->next->n)
			{
				swap_node(node, node->next);
				node = node->prev;
				cpt = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (cpt == 0)
			return;
		cpt = 0;

		node = node->prev;

		while (node->prev || node->n > node->next->n)
		{
			if (node->n > node->next->n)
			{
				swap_node(node, node->next);
				node = node->prev;
				if (node->prev == NULL)
					*list = node;
				cpt = 1;
				print_list(*list);
			}
			if (node->prev)
				node = node->prev;
		}
	}
}
