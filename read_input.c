#include "simple_shell.h"
/**
 * read_input - read a line from stdin
 * Return: pointer to the line
 */
char *read_input(void)
{
	char *uinput = NULL;
	size_t bufsize = 0;
	ssize_t status;

	status = getline(&uinput, &bufsize, stdin);

	if (status == -1)
	{
		free(uinput);
		return (NULL);
	}
	return (uinput);
}
