#include "sort.h"

/**
 * swap_node - function to swap node with previous node
 * @node: node to be swaped with previous one
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
