#include "shell.h"

/**
 * exec_cmd - Execute a command string using execve
 * @str: The string to execute
 * @program: The program name to be used in case of an error.
 *
 * Return: None
 */
void exec_cmd(char *str, const char *program)
{
	pid_t pid;
	int status, res;
	char *path, *envp[] = {NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		char **args = split(str, ' ');

		trim(args[0]);
		/*  Check whether a command is executable */
		if (access(args[0], X_OK) != 0)
		{
			path = get_command_path((const char *)args[0]);
			if (path == NULL)
			{
				perror(program);
				delete_array(args);
				exit(EXIT_FAILURE);
			}
			args[0] = path;
		}
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
	free(str);
}
