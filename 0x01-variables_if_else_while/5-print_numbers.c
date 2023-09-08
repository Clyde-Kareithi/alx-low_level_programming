#include <stdio.h>

/**
* main - Entry point of the program
*
* Description: Prints all single-digit numbers of base 10
*              starting from 0, followed by a new line.
*
* Return: Always 0 (Success)
*/
int main(void)
{
    int digit; // Declare variable at the beginning of the block

    for (digit = 0; digit <= 9; digit++)
    {
        putchar(digit + '0'); // Print the digit as a character
        putchar('\n');        // Print a newline character
    }

    return (0);
}

