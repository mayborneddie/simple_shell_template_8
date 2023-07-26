#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - Reads a line from a file descriptor
 * @line_ptr: A pointer to a buffer to store the line
 * @line_size: The initial size of the buffer
 * @fd: The file descriptor to read from
 *
 * Return: The number of bytes read, including the newline character,
 *         or -1 if an error occurred
 */
ssize_t _getline(char **line_ptr, size_t *line_size, int fd)
{
	static char buffer[1024];
	static char *buffer_ptr = buffer;
	static int chars_left, chars_read;

	*line_ptr = realloc(*line_ptr, *line_size);
	if (!line_ptr || !line_size || !*line_ptr)
		return (-1);

	chars_read = read(fd, buffer_ptr, 1024);
	while (chars_read)
	{
		buffer_ptr = buffer;
		chars_left = chars_read;

		while (chars_left > 0)
		{
			if ((*line_ptr)[chars_left - 1] == '\n')
			{
				(*line_ptr)[chars_left] = '\0';
				return (chars_left);
			}

			*line_ptr = realloc(*line_ptr, *line_size *= 2);
			if (chars_left == (int)*line_size && !*line_ptr)
				return (-1);

			(*line_ptr)[chars_left++] = *buffer_ptr++;
		}

		chars_read = read(fd, buffer_ptr, 1024);
	}

	return (chars_left ? chars_left : -1);
}
