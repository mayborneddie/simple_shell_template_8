#include "shell.h"

/**
 * exec_cmd - Execute a command string using execve
 * @command: The command string to execute
 * @program: The program name to be used in case of an error.
 *
 * Return: None
 */
void exec_cmd(char *command, const char *program)
{
	char *args[] = {NULL};

	if (execve(command, args, NULL) == -1)
	{
		perror(program);
		exit(EXIT_FAILURE);
	}
}
