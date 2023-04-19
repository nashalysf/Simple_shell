#include "simple_shell.h"
/**
 * main - gets user input and calls
 * function(s) to preform command
 * @ac: argument count
 * @argv: argument vector (array)
 * Return: 0. for success
 */
int main(int ac, char **argv)
{
/*
 * lineptr- stores address of buffered input
 * n- stores allocated input size in bytes
 * stdin - std input used as stream of data source
 * free()- must be freed by dev
 */
	char *lineptr;
	size_t n = 0;

/* prompt */
	char *prompt = "~$";
	char *username = getlogin();
	printf("%s%s",username, prompt);

	(void)ac;
	(void)argv;

/* copies, displays, and realeases input */
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);
	free(lineptr);
	return (0);
}
