#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments provided
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: Always returns 0.
 */
int main(int argc __attribute__((unused)), char const *argv[])
{
	char *str, **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print("#cisfun$ ");
		str = readline();
		if (str == NULL)
			break;

		trim(str);
		args = split(str, ' ');
		if (is_equal(str, "exit"))
		{
			free(str);
			free(args);
			exit(EXIT_SUCCESS);
		}
		if (builtin_env(args))
			continue;
		free(args);
		exec_cmd(str, argv[0]);
	}
	return (0);
}
