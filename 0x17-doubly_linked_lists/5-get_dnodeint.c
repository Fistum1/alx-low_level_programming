#include "lists.h"

/**
 * get_dnodeint_at_index - The function that gets nth node of a list at index
 * @head: A pointer to head of list.
 * @index: A position of node starting from 0.
 * If the node does not exist, return NULL.
 *
 * Return: The nth node of a dlistint_t linked list.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;

	/* It checks if head is NULL */
	if (!head)
		return (NULL);

	/* A while head is not NULL */
	while (head != NULL)
	{
		/* It initializes search here */
		if (i == index)
			break;
		i++;
		/* make head point to next if index is not found */
		head = head->next;
	}
	/* It returns the node */
	return (head);
}
