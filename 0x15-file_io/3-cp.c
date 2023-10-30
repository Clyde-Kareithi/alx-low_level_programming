#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

/**
 * main - Copy content from file_from to file_to.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, or exit with appropriate error codes.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (copy_file(argv[1], argv[2]) != 0)
	{
	exit(98);
	}

	return (0);
}

/**
 * copy_file - Copy the content from file_from to file_to.
 * @from: Source file.
 * @to: Destination file.
 * Return: 0 on success, -1 on failure.
 */
int copy_file(const char *from, const char *to)
{
	int fd_from, fd_to;
	ssize_t n_read, n_write;
	char buffer[BUFSIZE];

	fd_from = open(from, O_RDONLY);
	if (fd_from == -1)
	return (-1);

	fd_to = open(to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		return (-1);
	}

	while ((n_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		n_write = write(fd_to, buffer, n_read);
		if (n_write == -1)
		{
			close(fd_from);
			close(fd_to);
		return (-1);
		}
	}

	close(fd_from);
	close(fd_to);

	if (n_read == -1)
	return (-1);

	return (0);
}

