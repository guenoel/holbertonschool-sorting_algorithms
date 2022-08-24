#include "sort.h"

/**
 * insertion_sort_list - order with insertion sort
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *node = *list;
    listint_t *tmpswap = node;

    node = node->next;

    while (node->n > node->prev->n)
    {
        node = node->next;
    }

    tmpswap = node;
    node = node->prev;
    node->next = tmpswap;
    
    node = node->prev;
    print_list(*list);

    while (node->n < node->prev->n)
    {
        tmpswap = node;
        node = node->prev;
        node->next = tmpswap;

        node = node->prev;
        print_list(*list);
        break;
    }

    node = tmpswap;
}