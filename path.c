#include "shell.h"
#include "shell.h"

/**
 * get_command_path - Finds the absolute path
 * of a command in the PATH environment variable
 * @command: The name of the command to find
 *
 * Return: A pointer to a string containing the absolute
 * path of the command, or NULL if the command was not found
 */
char *get_command_path(const char *command)
{
	char *path = _getenv("PATH");
	char *token = _strtok(path, ":");
	size_t command_len = _strlen(command);

	while (token != NULL)
	{
		size_t dir_len = _strlen(token);
		char *abs_path = malloc(dir_len + 1 + command_len + 1);

		if (abs_path == NULL)
			return (NULL);

		_memcpy(abs_path, token, dir_len);
		abs_path[dir_len] = '/';
		_memcpy(abs_path + dir_len + 1, command, command_len);
		abs_path[dir_len + 1 + command_len] = '\0';

		if (access(abs_path, F_OK) == 0)
			return (abs_path);
		free(abs_path);
		token = _strtok(NULL, ":");
	}

	return (NULL);
}
