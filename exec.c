#include "shell.h"

/**
 * exec_cmd - Execute a command string using execve
 * @command: The command string to execute
 *
 * Return: None
 */
void exec_cmd(char *command)
{
	char *args[] = {NULL};

	if (execve(command, args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
