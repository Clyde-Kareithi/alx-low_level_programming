#include "main.h"
#include <stdio.h>

/**
 * error_handling - Check if files can be opened and handle errors.
 * @src_fd: Source file descriptor.
 * @dest_fd: Destination file descriptor.
 * @argv: Command-line arguments.
 */
void error_handling(int src_fd, int dest_fd, char *argv[])
{
	if (src_fd == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
		}
	if (dest_fd == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
		}

}

/**
 * main - Copy content from the source file to the destination file.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, close_err;
	ssize_t num_read, num_written;
	char buffer[1024];

	if (argc != 3)
		{
		dprintf(STDERR_FILENO, "%s\n", "Usage: my_cp source_file destination_file");
		exit(97);
		}

	src_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_handling(src_fd, dest_fd, argv);

	num_read = 1024;
	while (num_read == 1024)
	{
		num_read = read(src_fd, buffer, 1024);
	if (num_read == -1)
		error_handling(-1, 0, argv);
		num_written = write(dest_fd, buffer, num_read);
	if (num_written == -1)
		error_handling(0, -1, argv);
	}

	close_err = close(src_fd);
	if (close_err == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
		}

	close_err = close(dest_fd);
	if (close_err == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
		}

	return (0);
}

