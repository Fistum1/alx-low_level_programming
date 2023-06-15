#include "lists.h"

/**
 * add_dnodeint - The function that adds new node at begininning of a dbly,
 * linked list.
 *
 * @head: A pointer to pointer to head of list.
 * @n: A data to be added.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int nx)
{
	dlistint_t *new_node;

	/* Allocating a memory for new node */
	new_node = malloc(sizeof(dlistint_t));

	/* If it fails return NULL */
	if (new_node == NULL)
		return (NULL);

	/* Assigning data to new node */
	new_node->nx = nx;

	/* A point next of newNode to the first node of the doubly linked list */
	new_node->next = *head;

	/* A point previous of new node to NULL */
	new_node->prev = NULL;

	/* A point prev of 1st node (now 1st node is the second node) to new node */
	if ((*head) != NULL)
		(*head)->prev = new_node;

	/* A head points to newNode */
	(*head) = new_node;

	return (new_node);
}
