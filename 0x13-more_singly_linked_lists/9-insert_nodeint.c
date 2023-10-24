#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to a pointer to the head of the list.
 * @idx: The index where the new node should be added. Index starts at 0.
 * @n: The integer value to add to the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i = 0;

	if (head == NULL)
	return (NULL);

	if (idx == 0)
	return (add_nodeint(head, n));

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);  /* Allocation failed */

	new_node->n = n;
	current = *head;

	while (current != NULL && i < idx - 1)
	{
	current = current->next;
	i++;
	}

	if (current == NULL)
	{
	free(new_node);
	return (NULL);  /* Index out of range, insertion failed */
	}

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

