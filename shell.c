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
		do {
			_print("#cisfun$ ");
			str = readline();
			exec_cmd(str, argv[0]);
		} while (is_equal(str, "exit") == 0);
	else

		while ((str = readline()) != NULL)
		{
			exec_cmd(str, argv[0]);
			free(str);
		}

	return (0);
}
