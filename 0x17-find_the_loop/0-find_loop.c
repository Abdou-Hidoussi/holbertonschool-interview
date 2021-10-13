#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Pointer to a struct
 *
 * Return: Address node where loop starts or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *one = head;
	listint_t *two = head;

	while (one && two && two->next)
	{
		two = two->next->next;
		one = one->next;
		if (one == two)
		{
			one = head;
			while (two != one)
			{
				two = two->next;
				one = one->next;
			}
			return (one);
		}
	}
	return (NULL);
}
