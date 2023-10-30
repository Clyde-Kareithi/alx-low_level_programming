#include "main.h"
#include <fcntl.h>

/**
 * read_textfile - Reads and prints a text file to stdout
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 * Return: The actual number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, bytes_read, bytes_written;
	char *buf;

	if (filename == NULL)
	return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);

	buf = malloc(letters);
	if (buf == NULL)
	{
	close(fd);
	return (0);
	}

	bytes_read = read(fd, buf, letters);
	if (bytes_read == -1)
	{
	free(buf);
	close(fd);
	return (0);
	}

	bytes_written = write(STDOUT_FILENO, buf, bytes_read);
	if (bytes_written == -1 || (size_t)bytes_written != (size_t)bytes_read)
	{
	free(buf);
	close(fd);
	return (0);
	}

	free(buf);
	close(fd);
	return (bytes_read);
}

