#include "shell.h"
/**
 * exit_with_error - Print an error message and exit
 * the program with a failure status code
 *
 * @error: The error message to print
 *
 * Return: None
 */
void exit_with_error(const char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
