#include "sort.h"

/**
 * swap_node - function to swap node with previous node
 * @node: node to be swaped with previous one
 *
 * Return: Nothing
 */

void swap_node(listint_t *node)
{
	listint_t *tmp1; /*x*/
	listint_t *tmp2; /*z then w*/
	listint_t *tmp3; /*y*/

	tmp1 = node->prev; /*x*/
	tmp2 = node_next; /*z*/
	node->prev = node->prev->prev; /*w*/
	node->next = tmp; /*x*/

	node = node->next; /*move to x*/

	node->next = tmp2; /*z*/
	tmp2 = node->prev; /*w - new assignement to tmp2*/
	node->prev = node->next; /*y*/
	tmp3 = node->prev; /*y*/

	if (tmp3->prev)
	{
	node = tmp2; /*move to w*/
	node->next = tmp3; /*y*/
	}

	if (tmp1->next)
	{
	node = node->next->next->next; /*move to z*/
	node->prev = tmp; /*x*/
	}
}
