#include "shell.h"

/**
 * _putchar - Writes a single character to stdout
 * @c: The character to write
 *
 * Return: On success, returns the character written. On failure, returns -1.
 */
int _putchar(int c)
{
	char ch = (char)c;
	ssize_t bytes_written = write(STDOUT_FILENO, &ch, 1);

	if (bytes_written == -1)
	{
		return (-1);
	}

	return (ch);
}
/**
 * _print - Print a string to the standard output
 * @str: Pointer to the string to be printed
 *
 * Return: void
 */
void _print(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str != NULL)
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * is_equal - Check if two strings are equal
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 1 if the strings are equal, otherwise 0
 */
int is_equal(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (0);
		}
		i++;
	}

	return (1);
}
/**
 * _strncmp - Compare two strings up to a specified number of characters
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: An integer indicating the relationship
 * between the first n characters of s1 and s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		else if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
	}
	return (0);
}
