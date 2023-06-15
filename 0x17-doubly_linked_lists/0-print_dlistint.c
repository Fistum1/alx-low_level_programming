#include "lists.h"

/**
 * print_dlistint - A doubly linked lists
 * @h: A poiner to the head of the list
 *
 * Return: The number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	/* while we have a pointer to the list */
	while (h != NULL)
	{
		printf("%d\n", h->nx);
		count++;
		h = h->next;
	}
	return (count);
}
