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

	if (isatty(0))
	{
		while (1)
		{
			_print("#cisfun$ ");
			str = readline();
			if (str == NULL)
			{
				free(str);
				continue;
			}
			trim(str);
			if (is_equal(str, "exit") == 1)
			{
				free(str);
				exit(EXIT_SUCCESS);
			}
			exec_cmd(str, argv[0]);
			free(str);
		}
	}
	else

		while ((str = readline()) != NULL)
		{
			trim(str);
			exec_cmd(str, argv[0]);
			free(str);
		}

	return (0);
}
