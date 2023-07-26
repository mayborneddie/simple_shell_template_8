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
