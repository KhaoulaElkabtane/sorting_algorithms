#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @lst: Pointer to a pointer to the head of the list.
 * @lst1: Pointer to a pointer to the first node to be swapped.
 * @lst2: Pointer to the second node to be swapped.
 * Return : Nothing
 */
void swap_nodes(listint_t **lst, listint_t **lst1, listint_t *lst2)
{
	(*lst1)->next = lst2->next;
	if (lst2->next != NULL)
		lst2->next->prev = *lst1;
	lst2->prev = (*lst1)->prev;
	lst2->next = *lst1;
	if ((*lst1)->prev != NULL)
		(*lst1)->prev->next = lst2;
	else
		*lst = lst2;
	(*lst1)->prev = lst2;
	*lst1 = lst2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Pointer to a pointer to the head of the list.
 * Return : Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lst, *isr, *ins;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (lst = (*list)->next; lst != NULL; lst = ins)
	{
		ins = lst->next;
		isr = lst->prev;
		while (isr != NULL && lst->n < isr->n)
		{
			swap_nodes(list, &isr, lst);
			print_list((const listint_t *)*list);
		}
	}
}
