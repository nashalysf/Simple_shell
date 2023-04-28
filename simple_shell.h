#ifndef _SHELL_
#define _SHELL_

/* ----------------LIBRARIES---------------- */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
/* -----------------PROTOTYPES-------------- */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
/*
 * str - string to tokenize
 * delim - guide to break the string
 */
char *strtok(char *str, const char *delim);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void _pwd(void);
int execute(char **args);
char *read_input(void);
void _ls(void);
void free_array(char **args);
void prompt(void);
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"


char **tokenize(char *lineptr);
int forks(char *find, char **argv, size_t *counter);
int path(const char *file_name, DIR *dir);

/***enviroment var***/
extern char **envar;
#endif
