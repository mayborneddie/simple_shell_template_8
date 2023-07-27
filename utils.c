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

/**
 * _strlen - Calculates the length of a string
 * @str: The string to calculate the length of
 *
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
/**
 * _strtok - Find the next token in a string
 *
 * @str: The string to tokenize
 * @delim: The delimiter characters
 *
 * Return: A pointer to the next token in the string, or NULL if there are no
 *         more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *token = NULL;

	if (str != NULL)
		last_token = str;

	if (last_token == NULL)
		return (NULL);

	token = last_token;

	while (*last_token != '\0')
	{
		const char *d = delim;

		while (*d != '\0')
		{
			if (*last_token == *d)
			{
				*last_token = '\0';
				last_token++;
				if (*last_token != '\0')
					return (token);

				last_token = NULL;
				return (token);
			}
			d++;
		}
		last_token++;
	}
	last_token = NULL;
	return (token);
}
