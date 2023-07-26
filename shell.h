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
char **split(char *str, char delimiter);
size_t _len(char **arr);

/* Environ */
void print_env(void);

/* Memory */
void *_memchr(const void *s, int c, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, size_t size);
void delete_array(char **arr);

#endif
