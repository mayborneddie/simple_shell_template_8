#include "shell.h"

/**
 * readline - Reads a line of input from stdin
 *
 * Return: A pointer to the input line, or NULL on failure
 */
char *readline(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t linelen;

	linelen = getline(&input, &bufsize, stdin);

	if (linelen == -1)
	{
		free(input);
		input = NULL;
	}
	else
	{
		if (input[linelen - 1] == '\n')
		{
			input[linelen - 1] = '\0';
		}
	}

	return (input);
}
