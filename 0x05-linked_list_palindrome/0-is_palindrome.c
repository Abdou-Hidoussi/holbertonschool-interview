#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: singly linked list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *count, *last, *before;

	count = *head;
	last = count;
	while (last->next != NULL)
		last = last->next;

	while (count->next != last && count->n == last->n)
	{
		count = count->next;
		before = last;
		last = count;
		while (last->next != before && last->next != NULL)
			last = last->next;
	}

	if (count->next == last && count->n == last->n)
		return (1);
	else
		return (0);
}
