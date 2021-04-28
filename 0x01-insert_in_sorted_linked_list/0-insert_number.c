#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


listint_t *insert_node(listint_t **head, int number)
{
    listint_t *count, *new, *tmp;
    
    if (!*head)
        return NULL;
    count = *head;
    new = malloc(sizeof(listint_t *));
    if (!new)
        return NULL;

    new->n = number;
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
