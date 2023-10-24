#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *next;

	if (!h)
	return (0);

	current = *h;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
		size++;
	}

	*h = NULL;

	return (size);
}

