#include <stdio.h>

/**
* main - finds and prints the sum of the even-valued terms
* followed by a new line
* Return: Always 0 (Success)
*/

int main(void)
{
	int i;
	unsigned long int j, k, next, sum;

	j = 1;
	k = 2;
	sum = 0;

	while (j <= 4000000)
	{
	if (j % 2 == 0)
	{
	sum += j;
	}
	next = j + k;
	j = k;
	k = next;
	}

	printf("%lu\n", sum);

	return 0;
}

