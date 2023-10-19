#include <stddef.h>  /* for size_t */
#include "list.h"    /* Replace "list.h" with your actual header file name */
#include <stdio.h>   /* for printf */

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: A pointer to the head of the list.
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)

	{
	if (h->str == NULL)
	printf("[0] (nil)\n");
	else
	printf("[%u] %s\n", h->len, h->str);
	h = h->next;
	node_count++;
}
return (node_count);
}

