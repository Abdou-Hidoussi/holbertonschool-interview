#include "list.h"
/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);

	if (!*list)
	{
		*list = new;
		(*list)->next = (*list)->prev = new;
	}
	else
	{
		new->prev = (*list)->prev, new->next = *list;
		(*list)->prev = (*list)->prev->next = new;
	}
	return (new);
}
/**
 * add_node_begin - Add a new node to the beginning of
 * a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);

	if (!*list)
	{
		*list = new;
		(*list)->next = (*list)->prev = new;
	}
	else
	{
		new->prev = (*list)->prev, new->next = *list;
		(*list)->prev = (*list)->prev->next = new;
	}
	*list = new;
	return (new);
}
