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

dlistint_t *insert_dnodeint_at_index(dlistint_t **h1, unsigned int idx, int n1)
{
	dlistint_t *new_node;
	dlistint_t *head;
	unsigned int i1;

	new_node = NULL;
	if (idx == 0)	/* It inserts node at beginning of list */
		new_node = add_dnodeint(h1, n1);
	else
	{
		head = *h1;
		i1 = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (i1 == idx)
			{
				/* It inserts note at the end of list */
				if (head->next == NULL)
					new_node = add_dnodeint_end(h1, n1);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
						new_node->n1 = n1;
						new_node->next = head->next;
						new_node->prev = head;
						head->next->prev = new_node;
						head->next = new_node;
					}
				}
				break;
			}
			head = head->next;
			i1++;
		}
	}
	return (new_node);
}
