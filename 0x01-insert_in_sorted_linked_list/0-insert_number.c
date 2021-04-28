#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a new node at a sorted listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *count, *new, *tmp;

	if (!*head)
		return (NULL);
	count = *head;
	new = malloc(sizeof(listint_t *));
	if (!new)
		return (NULL);

	new->n = number;
	if (number < count->n)
	{
		new->next = count;
		*head = new;
		return (new);
	}
	while (count)
	{
		if (count->next && number < count->next->n)
		{
			tmp = count->next;
			count->next = new;
			new->next = tmp;
			break;
		}

		if (count->next)
			count = count->next;
		else
		{
			count->next = new;
			break;
		}
	}
	return (new);
}
