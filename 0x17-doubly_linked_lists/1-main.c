#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - It checks the code
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *new;
	dlistint_t hello = {8, NULL, NULL};
	size_t n1;

	head = &hello;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (EXIT_FAILURE);
	}
	new->n1 = 9;
	head->prev = new;
	new->next = head;
	new->prev = NULL;
	head = new;
	n1 = dlistint_len(head);
	printf("-> %lu elements\n", n1);
	free(new);
	return (EXIT_SUCCESS);
}
