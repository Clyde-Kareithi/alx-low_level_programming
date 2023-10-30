#include "main.h"
#include <stdio.h>

/**
 * checkFiles - Check if files can be opened and handle errors.
 * @fileFrom: File descriptor for the source file.
 * @fileTo: File descriptor for the destination file.
 * @arguments: Command-line arguments.
 */

void checkFiles(int fileFrom, int fileTo, char *arguments[]);

/**
 * main - Copy content from the source file to the destination file.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 * Return: Always 0.
 */


int main(int argc, char *argv[])
{
	int fileFrom, fileTo, errorClose;
	ssize_t numChars, numWritten;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: my_cp source_file destination_file");
		exit(97);
	}

	fileFrom = open(argv[1], O_RDONLY);
	fileTo = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	checkFiles(fileFrom, fileTo, argv);

	numChars = 1024;
	while (numChars == 1024)
	{
		numChars = read(fileFrom, buffer, 1024);
		if (numChars == -1)
			checkFiles(-1, 0, argv);
		numWritten = write(fileTo, buffer, numChars);
		if (numWritten == -1)
			checkFiles(0, -1, argv);
	}

	errorClose = close(fileFrom);
	if (errorClose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}

	errorClose = close(fileTo);
	if (errorClose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}
	return (0);
}

void checkFiles(int fileFrom, int fileTo, char *arguments[])
{
	if (fileFrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arguments[1]);
		exit(98);
	}
	if (fileTo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", arguments[2]);
		exit(99);
	}
}

