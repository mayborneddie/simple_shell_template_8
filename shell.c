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
	char *str = NULL, **args = NULL;
	int exit_code = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print("#cisfun$ ");
		FREE_TWO(args, str);
		str = readline();
		if (str == NULL)
			break;

		trim(str);
		args = split(str, ' ');
		trim(args[0]);
		if (is_equal(args[0], "exit"))
		{
			if (args[1] != NULL)
				exit_code = atoi(args[1]);
			FREE_TWO(args, str);
			exit(exit_code);
		}
		if (builtin_env(args))
		{
			FREE_TWO(args, str);
			continue;
		}
		exec_cmd(args, argv[0]);
	}
	return (0);
}
