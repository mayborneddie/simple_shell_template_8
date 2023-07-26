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
	int status, res;

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

		res = execve(args[0], args, envp),
		delete_array(args);
		if (res == -1)
		{
			perror(program);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(command);
}
