#include <stdio.h>

/**
* main - Entry point of the program
*
* Description: Prints all single-digit numbers of base 10 starting from 0, followed by a new line.
*
* Return: Always 0 (Success)
*/
int main(void)
{
    int digit; // Declare variable at the beginning of the block

    for (digit = 0; digit <= 9; digit++)
    {
        printf("%d\n", digit);
    }

    return (0);
}

