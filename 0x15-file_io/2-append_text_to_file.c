#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: The name of the file
 * @text_content: The text to append
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, result, text_len;

	if (filename == NULL)
	return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	return (-1);

	if (text_content != NULL)
	{
		for (text_len = 0; text_content[text_len]; text_len++)
		continue;

		result = write(fd, text_content, text_len);
	if (result == -1)
		{
		close(fd);
		return (-1);
		}
	}

	close(fd);
	return (1);
}

