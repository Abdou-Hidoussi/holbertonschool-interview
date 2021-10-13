#include "search.h"
/**
 * check_list - Check if the value is between first and last
 *@first: first element of the bracket
 *@last: last element of the bracket
 *@value: the value we are searching for
 * Return: element or null
 */
skiplist_t *check_list(skiplist_t *first, skiplist_t *last, int value)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
	first->index, last->index);

	while (first != last->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		first->index, first->n);

		if (first->n == value)
			return (first);
		first = first->next;
	}

	return (NULL);
}
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *@list: list of element
 *@value: the value we are searching for
 * Return: element or null
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *this;

	while (list)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		list->express->index, list->express->n);


		if (list->express->n >= value)
			return (check_list(list, list->express, value));


		list = list->express;

		if (!list->express)
		{
			this = list;
			while (this->next != NULL)
				this = this->next;
			return (check_list(list, this, value));
		}
	}
	return (NULL);
}
