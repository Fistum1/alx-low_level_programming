#include "lists.h"

/**
 * print_dlistint - A function that prints all the elemts of a doubly linked list
 * 
 * @h: A poiner to the head of the list
 *
 * Return: The number of nodes
 */

size_t print_dlistint(const dlistint_t *h1)
{
	size_t count = 0;

	/* while we have a pointer to the list */
	while (h1 != NULL)
	{
		printf("%d\n1", h1->n1);
		count++;
		h1 = h1->next;
	}
	return (count);
}
