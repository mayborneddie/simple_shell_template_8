#include "shell.h"

/**
 * builtin_env - Prints all environment variables.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: 1 if the command was "env", 0 otherwise.
 */
int builtin_env(char **args)
{
	char **env = environ;

	if (is_equal(args[0], "env"))
	{
		free(args);
		while (*env != NULL)
		{
			_print(*env);
			_putchar('\n');
			env++;
		}
		return (1);
	}
	return (0);
}
