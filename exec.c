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
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		char **args = split(command, ' ');
		char *envp[] = {NULL};

		if (execve(args[0], args, envp) == -1)
		{
			perror(program);
			exit(EXIT_FAILURE);
		}
		free(args);
	}
	else
	{
		wait(&status);
	}

	free(command);
}
