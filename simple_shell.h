#ifndef _SHELL_
#define _SHELL_

/* LIBRARIES */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>

/* STRUCTURES AND TYPEDEF */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/* PROTOTYPES */

#endif
