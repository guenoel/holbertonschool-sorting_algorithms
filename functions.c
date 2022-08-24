#include "sort.h"

/**
 * swap_node - function to swap node with previous node
 * @node: node to be swaped with previous one
 *
 * Return: Nothing
 */

void swap_node-node_prev(listint_t *node)
{
	listint_t *tmp1; /*x*/
	listint_t *tmp2; /*z*/
	listint_t *tmp3; /*y*/

	tmp1 = node->prev; /*x*/
	tmp2 = node->next; /*z*/
	tmp3 = node; /*y*/

	node->prev = node->prev->prev; /*w (possible = NULL)*/
	node->next = tmp1; /*x*/

	node = node->next; /*move to x*/

	node->next = tmp2; /*z (possible = NULL)*/
	node->prev = node->next; /*y*/

	if (tmp3->prev)
	{
	node = tmp3->prev; /*move to w*/
	node->next = tmp3; /*y*/
	}

	if (tmp1->next)
	{
	node = tmp1->next; /*move to z*/
	node->prev = tmp1; /*x*/
	}
	node = tmp3;
	printf("node tmp3: %d\n", node->n);
}

void swap_node(listint_t *node1, listint_t *node2)
