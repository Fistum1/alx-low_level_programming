#include "lists.h"

/**
 * free_dlistint - The function that frees a dbly inked list.
 * @head: A pointer to head of list.
 *
 * Return: No return.
 */

void free_dlistint(dlistint_t *head)
{
	/* It checks if head is NULL and return if so */
	while (head != NULL)
	{
		/* It traverses the list freeing each node */
		dlistint_t *next = head->next;

		free(head);

		head = next;
	}
}

