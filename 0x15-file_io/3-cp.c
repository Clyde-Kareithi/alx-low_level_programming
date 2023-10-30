#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, or exit with appropriate error codes.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t n_read, n_write;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
		}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
		}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
		}

	while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
	n_write = write(fd_to, buffer, n_read);
	if (n_write == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
		}
	}

	if (n_read == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
		}

	if (close(fd_from) == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
		}

	if (close(fd_to) == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
		}

return (0);
}

