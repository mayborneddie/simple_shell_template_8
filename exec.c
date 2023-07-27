#include "shell.h"

/**
 * exec_cmd - Execute a command with arguments
 *
 * @args: Pointer to an array of strings
 * containing the command and its arguments
 * @program: Name of the current program
 *
 * Return: void
 */
void exec_cmd(char **args, const char *program)
{
	pid_t pid;
	int status;
	char *path = NULL;
	char *envp[] = {NULL};

	pid = fork();

	if (pid == -1)
	{
		perror(program);
		return;
	}
	else if (pid == 0)
	{
		if (access(args[0], X_OK) != 0)
		{
			path = get_command_path(args[0]);
			if (path == NULL)
			{
				perror(program);
				return;
			}
			args[0] = path;
		}
		if (execve(args[0], args, envp) == -1)
		{
			perror(program);
			return;
		}
	}
	else
		waitpid(pid, &status, 0);
	free(path);
}
