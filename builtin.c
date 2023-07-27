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
/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable to retrieve
 *
 * Return: If the environment variable is found,
 * a pointer to its value is returned.
 */
char *_getenv(const char *name)
{
	char **ep;

	if (name == NULL || *name == '\0')
		return (NULL);

	for (ep = environ; *ep != NULL; ep++)
	{
		if (_strncmp(name, *ep, _strlen(name)) == 0 && (*ep)[_strlen(name)] == '=')
			return (&((*ep)[_strlen(name) + 1]));
	}

	return (NULL);
}
