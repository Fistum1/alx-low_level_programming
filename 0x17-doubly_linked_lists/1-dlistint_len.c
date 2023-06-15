#include "lists.h"

/**
 * dlistint_len - The function that returns the number of elements in a,
 * linked dlistint_t list.
 * 
 * @h: A poiner to the head of the list
 *
 * Return: The number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	/* while we have a pointer to the list */
	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
