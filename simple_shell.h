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
/* -----------------PROTOTYPES-------------- */

/* ac __attribute__((unused)) -
 * tells arg count while preventing warnings if unused 
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
/* str - string to tokenize
 * delim - guide to break the string
 */
char *strtok(char *str, const char *delim);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void _pwd(void);

void _ls(void);

#endif
