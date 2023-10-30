#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Copy content from file_from to file_to.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, or exit with appropriate error codes.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t n_read, n_write;
	char buffer[1024];

	if (argc != 3)
		{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
		}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
		}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		exit(99);
		}

	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_write = write(fd_to, buffer, n_read);
	if (n_write == -1)
		{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		exit(99);
		}
	}

	if (n_read == -1)
	{
	dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}

