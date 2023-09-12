#include "main.h"

/**
* _islower - check if char is lowercase
* @c: is the char to be checked
* Return: 1 if char is lowercase, otherwise 0.
*/

void print_alphabet_x10(void)
{
	char ch;
	int i;

	i = 0;

	while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}

