#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @bin: A pointer to a string containing binary digits (0 and 1).
 *
 * Return: The converted unsigned integer, or 0 if any character in the
 * string is not '0' or '1' or if bin is NULL.
 */
unsigned int binary_to_uint(const char *bin)
{
	int index;
	unsigned int result = 0;

	if (!bin)
	return (0);

	for (index = 0; bin[index] != '\0'; index++)
	{
	if (bin[index] != '0' && bin[index] != '1')
	return (0);
	}

	for (index = 0; bin[index] != '\0'; index++)
	{
	result <<= 1;
	if (bin[index] == '1')
	result += 1;
	}

	return (result);
}

