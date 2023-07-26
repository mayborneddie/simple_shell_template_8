#ifndef SHELL
#define SHELL

/* Imports */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Macros*/
extern char **environ;

/* Readline */
char *readline();

/* String */
int _putchar(int c);
void _print(char *str);
int is_equal(char *str1, char *str2);

/* Exec */
void exec_cmd(char *command, const char *program);

/* Utils */
void trim(char *s);

/* Environ */
void print_env(void);

/* Getline */
ssize_t _getline(char **line_ptr, size_t *line_size, int fd);

/* Memory */
void *_memchr(const void *s, int c, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);

#endif
