#ifndef SHELL_H
#define SHELL_H

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

extern char **environ;
int _strlen(char *s);
int _strcmp(char *strg1, char *strg2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _str_n_cmp(const char *s1, const char *s2, size_t n);
void _printenv(char **environ);
int _getenv(int argc, char *argv[], char *envp[]);

#endif
