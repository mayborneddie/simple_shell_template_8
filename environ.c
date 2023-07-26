#include "shell.h"

/**
 * print_env - Prints all environment variables.
 */
void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_print(*env);
		_putchar('\n');
		env++;
	}
}
