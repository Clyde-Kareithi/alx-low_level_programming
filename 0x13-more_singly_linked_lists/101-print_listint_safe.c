#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count = 0;
	const listint_t *checker;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

	checker = head;
	if (current <= current->next && current < checker)
	{
	break;
	}

	current = current->next;
	}

	if (current <= current->next)
	{
		printf("-> [%p] %d\n", (void *)current->next, current->next->n);
		exit(98);
	}

	return (count);
}

