#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: singly linked list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *count, *last;

	count = *head;
	last = *head;

	if (!count || !count->next)
		return (1);

	while (last->next)
		last = last->next;

	while (count < last)
	{
		if (count->n == last->n)
		{
			count = count->next;
			last -= 2;
		}
		else
			return (0);
	}
	return (1);
}
