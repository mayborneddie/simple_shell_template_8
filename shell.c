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
	char *str;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print("#cisfun$ ");
		str = readline();
		if (str == NULL)
			break;

		trim(str);
		if (is_equal(str, "exit"))
		{
			free(str);
			exit(EXIT_SUCCESS);
		}
		if (is_equal(str, "env"))
		{
			free(str);
			print_env();
			continue;
		}
		exec_cmd(str, argv[0]);
	}

	return (0);
}
