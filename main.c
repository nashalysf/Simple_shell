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
	char *lineptr, *token, *lineptr_c = NULL;
	const char *delim = " \n";
	ssize_t read_getline;
	int token_n = 0, i = 0;
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
			printf("\nExiting Nadrian... Bye bye!\n");
			return (-1);
		}
		/*TOKEN: allocates space for copy of lineptr*/
		lineptr_c = malloc(sizeof(char *) * read_getline);
		if (lineptr_c == NULL)
		{
			perror("malloc error");
			return (-1);
		}
		/*copies lineptr to lineptr_c*/
		strcpy(lineptr_c, lineptr);
		/*split lineptr string into array of words and calculate total of tokens*/
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			token_n++;
			token = strtok(NULL, delim);
		}
		token_n++;

		/*allocate space to hold array of strings*/
		argv = malloc(sizeof(char *) * token_n);
/*possible leak: free malloc*/

		/*stores each token in argv array*/
		token = strtok(lineptr_c, delim);

		for (; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
/*possible leak: free malloc*/

			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		/*terminate array of string*/
		argv[i] = NULL;
		printf("%s\n", lineptr);
	}
	free(argv);
	free(lineptr);
	free(lineptr_c);

	return (0);

}
