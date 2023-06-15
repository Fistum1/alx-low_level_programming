#include "lists.h"

/**
 * insert_dnodeint_at_index - The function that inserts a new node at,
 * a given position.
 *
 * @h: A pointer to pointer to the h of linked list.
 * @idx: An index of the list where the new  node should be added.
 * @n: The value of the new node.
 *
 * If it is not possible to add the new node at index idx, do not,
 * add the new node and return NULL.
 *
 * Return:  The address of the new node, or NULL if it failed.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int nx)
{
	dlistint_t *new_node;
	dlistint_t *head;
	unsigned int i;

	new_node = NULL;
	if (idx == 0)	/* It inserts node at beginning of list */
		new_node = add_dnodeint(h, nx);
	else
	{
		head = *h;
		i = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (i == idx)
			{
				/* It inserts note at the end of list */
				if (head->next == NULL)
					new_node = add_dnodeint_end(h, nx);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
						new_node->nx = nx;
						new_node->next = head->next;
						new_node->prev = head;
						head->next->prev = new_node;
						head->next = new_node;
					}
				}
				break;
			}
			head = head->next;
			i++;
		}
	}
	return (new_node);
}
