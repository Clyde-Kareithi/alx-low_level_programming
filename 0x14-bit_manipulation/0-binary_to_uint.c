#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @b: A pointer to a string containing 0 and 1 characters.
 *
 * Return: The converted unsigned integer, or 0 if any character in the
 * string is not '0' or '1' or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)

{
	unsigned int result = 0;

	if (b == NULL)
	return (0);

	while (*b)
	{
	if (*b == '0' || *b == '1')
	{
		result = (result << 1) | (*b - '0');
		b++;
	}
	else
	{
	return (0);
	}
	}

	return (result);
}

