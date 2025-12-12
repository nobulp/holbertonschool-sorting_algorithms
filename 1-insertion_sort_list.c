#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insert;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insert = current;
		next = current->next;

		while (insert->prev != NULL && insert->prev->n > insert->n)
		{
			insert->prev->next = insert->next;
			if (insert->next != NULL)
				insert->next->prev = insert->prev;

			insert->next = insert->prev;
			insert->prev = insert->prev->prev;

			if (insert->prev != NULL)
				insert->prev->next = insert;
			else
				*list = insert;

			insert->next->prev = insert;

			print_list(*list);
		}
		current = next;
	}
}
