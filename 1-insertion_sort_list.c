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
	int cpt2 = 0;

	node = node->next;
	tmpswap = node;
	while (cpt)
	{
		cpt = 0;

		node = tmpswap;
		printf("node de debut de boucle %d\n", node->n);

		while (node->n > node->prev->n)
		{
			node = node->next;
		}

		tmpswap = node->prev;
		printf("tmpswap sauvé: %d\n", tmpswap->n);
		while (node->prev->n > node->n || node->prev != NULL)
		{
			swap_node(node);
			print_list(*list);
			cpt++;
			if (node->prev == NULL)
			{
				printf("prev NULL & break\n");
				break;
			}
			if (node->prev->prev == NULL)
			{
				printf("prev prev NULL\n");
				*list = node;
			}
			node = node->next;
			printf("Fin de boucle: node_prev_n: %d\n node_n: %d\n cpt: %d cpt2: %d\n", node->prev->n, node->n, cpt, cpt2);
			if (cpt2 == 1 || cpt == 1)
			exit(EXIT_FAILURE);
		}
			cpt2++;
	}
}
