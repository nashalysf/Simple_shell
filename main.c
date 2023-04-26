#include "simple_shell.h"
/**
 * tokenize- splits a string into an array of tokens
 * @lineptr: string to tokenize
 * Return: an array of strings with tokens
 */
char **tokenize(char *lineptr)
{
	const char *delim = " \n";
	char *token, *lineptr_c;
	char **argv;
	int token_n = 0, i = 0;

	/* allocate space for copy */
	lineptr_c = malloc(sizeof(char *) * strlen(lineptr + 1));
	if (lineptr_c == NULL)
	{
		perror("malloc error");
		return (NULL);
	}
	/* copy lineptr */
	strcpy(lineptr_c, lineptr);
	/* split lineptr string into array of words and calc total of tokens */
	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		token_n++;
		token = strtok(NULL, delim);
	}
	token_n++;

	/* allocate space to store array of strings */
	argv = malloc(sizeof(char *) * token_n);
/* possible leak */

	if (argv == NULL)
	{
	perror("malloc error");
	free(lineptr_c);
	return (NULL);
	}
	/* stores each token in argv array */
	token = strtok(lineptr_c, delim);
	for (; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token) + 1);
/* possible leak */
		if (argv[i] == NULL)
		{
			perror("malloc error");
			for (i--; i >= 0; i--)
				free(argv[i]);
			free(argv);
			free(lineptr_c);
			return (NULL);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	/* terminate array */
	argv[i] = NULL;
	free(lineptr_c);
	return (argv);
}
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
	char *lineptr =  NULL, **tokens;
	ssize_t read_getline;
	size_t n = 0;
	char *prompt = "~$";
	char *username = getlogin();
	(void)ac;

	/*prompt loop*/
	while (1)
	{
		printf("%s%s", username, prompt);
		read_getline = getline(&lineptr, &n, stdin);

		/*checks if getline failed and exits program*/
		if (read_getline == -1)
		{
			printf("\nExiting Nadrian...Bye bye!\n");
			return (-1);
		}
	/* tokenize tokens */
	tokens = tokenize(lineptr);
		if (tokens == NULL)
			return (-1);
	if (strcmp(tokens[0], "exit") == 0)
	{
		printf("\nExiting Nadrian...Bye bye!\n");
		break;
	}
	if (argv == NULL)
		return (-1);

	printf("%s\n", lineptr);
	}
	free(tokens);
	free(lineptr);
	return (0);
}
