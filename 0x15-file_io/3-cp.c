#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void error_handler(int code, char *file);
void copy_file(const char *file_from, const char *file_to);

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, or exit with appropriate error codes.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
		}

	copy_file(argv[1], argv[2]);
	return (0);
}

/**
 * copy_file - Copies the content of file_from to file_to.
 * @file_from: Source file.
 * @file_to: Destination file.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t n_read, n_write;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_handler(98, file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_handler(99, file_to);

	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
	n_write = write(fd_to, buffer, n_read);
	if (n_write == -1)
		error_handler(99, file_to);
	}

	if (n_read == -1)
	error_handler(98, file_from);

	if (close(fd_from) == -1 || close(fd_to) == -1)
	error_handler(100, NULL);
}

/**
 * error_handler - Exits with the appropriate error message and code.
 * @code: The error code.
 * @file: The name of the file associated with the error.
 */
void error_handler(int code, char *file)
{
	if (code == 98)
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	else if (code == 99)
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	else if (code == 100)
	dprintf(STDERR_FILENO, "Error: Can't close file\n");
	exit(code);
}

