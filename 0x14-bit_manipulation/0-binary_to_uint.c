#include "main.h"

/**
 * power_of_two - calculates the power of 2
 * @exp: exponent value
 *
 * Return: the result of 2 raised to the power of exp
 */
unsigned int power_of_two(int exp)
{
	if (exp == 0)
	return (1);

unsigned int result = 1;
	while (exp > 0)
	{
		result *= 2;
		exp--;
	}
	return result;
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int len = 0;
	unsigned int dec_val = 0;

	if (!b)
	return (0);


	while (b[len])
	{
	if (b[len] != '0' && b[len] != '1')
	return (0);
	len++;
	}

	for (int i = len - 1, exp = 0; i >= 0; i--, exp++)
	{
		if (b[i] == '1')
		dec_val += power_of_two(exp);
	}

	return dec_val;
}

