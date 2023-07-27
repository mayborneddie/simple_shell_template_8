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
	char **envp = environ, *path_var = NULL, *path, *command_path = NULL;
	size_t command_len;

	while (*envp != NULL)
	{
		if (_strncmp(*envp, "PATH=", 5) == 0)
		{
			path_var = *envp + 5;
			break;
		}
		envp++;
	}
	if (path_var == NULL)
		return (NULL);

	command_len = _strlen(command);
	path = _strtok(path_var, ":");

	while (path != NULL)
	{
		size_t path_len = _strlen(path);
		size_t full_path_len = path_len + command_len + 2;
		char *full_path = malloc(full_path_len);

		if (full_path == NULL)
			break;

		_memcpy(full_path, path, path_len);
		_memcpy(full_path + path_len, "/", 1);
		_memcpy(full_path + path_len + 1, command, command_len + 1);
		if (access(full_path, F_OK) == 0)
		{
			command_path = full_path;
			break;
		}
		free(full_path);
		path = _strtok(NULL, ":");
	}
	return (command_path);
}
