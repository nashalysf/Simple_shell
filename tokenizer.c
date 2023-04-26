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
                           for(i--; i >= 0; i--)
				   free(argv[i]);
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
