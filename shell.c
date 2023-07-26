#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *str;

	if (isatty(0))
		do {
			_print("#cisfun$ ");
			str = readline();
			exec_cmd(str);
		} while (is_equal(str, "exit") == 0);
	else

		while ((str = readline()) != NULL)
		{
			exec_cmd(str);
			free(str);
		}

	return (0);
}
