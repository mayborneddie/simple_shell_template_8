#include "shell.h"

/**
 * trim - Trim whitespace from both ends of a string
 * @s: The string to trim
 */
void trim(char *s)
{
	char *start = s;
	char *end = s;
	int len, i;

	while (*end != '\0')
		end++;

	end--;

	while (start <= end && (*start == ' ' || *start == '\t' || *start == '\n'))
		start++;

	while (end >= start && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;

	len = end - start + 1;

	if (start != s)
	{
		for (i = 0; i < len; i++)
		{
			s[i] = start[i];
		}
		s[len] = '\0';
	}
	else
		s[len] = '\0';
}
/**
 * split - Splits a string into an array of tokens based on a delimiter
 *
 * @str: The string to split
 * @delimiter: The delimiter character
 *
 * Return: An array of strings,
 * where each string is a token separated by the delimiter character.
 * The array ends with a NULL pointer.
 */
char **split(char *str, char delimiter)
{
	char **tokens = NULL;
	size_t num_tokens = 0;
	char *start = str;
	char *end;

	for (end = str; *end != '\0'; ++end)
	{
		if (*end == delimiter)
		{
			*end = '\0';
			tokens = _realloc(tokens, sizeof(char *) * (num_tokens + 1));
			tokens[num_tokens++] = start;
			start = end + 1;
		}
	}

	tokens = _realloc(tokens, sizeof(char *) * (num_tokens + 2));
	tokens[num_tokens++] = start;
	tokens[num_tokens] = NULL;

	return (tokens);
}
/**
 * _len - Returns the length of an array or string
 *
 * @arr: The array or string to get the length of
 *
 * Return: The number of elements in the array or the number of characters in
 * the string.
 */
size_t _len(char **arr)
{
	size_t count = 0;

	while (*arr != NULL)
	{
		count++;
		arr++;
	}
	return (count);
}
