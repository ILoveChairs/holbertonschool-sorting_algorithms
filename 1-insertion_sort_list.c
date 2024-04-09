#include "sort.h"
#include <stdlib.h>

/**
 * _replace - Does the replacing
 *
 * @i: DLL pointer that iterates.
 *
 * @list: head.
 */
void _replace(listint_t *i, listint_t **list)
{
	listint_t *tmp;

	while (i->prev && i->prev->n > i->n)
	{
		tmp = i->prev->prev;

		i->prev->next = i->next;
		i->prev->prev = i;
		i->next = i->prev;
		i->prev = tmp;

		if (i->prev)
			i->prev->next = i;
		else
			*list = i;

		if (i->next->next)
			i->next->next->prev = i->next;

		print_list(*list);
	}

}

/**
 * insertion_sort_list - Sorts by instertion.
 *
 * @list: Doubly linked list of ints.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	current = *list;
	while (current->next)
	{
		_replace(current, list);
		current = current->next;
	}
	_replace(current, list);
}



