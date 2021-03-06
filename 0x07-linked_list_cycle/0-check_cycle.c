#include "lists.h"
/**
 * check_cycle - function that checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *head, *count;

	count = head = list;
	while (head && count && count->next)
	{
		head = head->next;
		count = count->next->next;

		if (count == head)
			return (1);
	}
	return (0);
}
