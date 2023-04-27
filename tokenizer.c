#include "simple_shell.h"
/**
 * tokenize - splits a string into an array of tokens
 * @lineptr: string to tokenize
 *
 * Return: an array of strings with tokens
 */
char **tokenize(char *str)
{
        char **tokens = NULL;
        char *token = NULL;
        int idx = 0;

        tokens = malloc(sizeof(char *) * TOK_BUFSIZE);
        if (!tokens)
        {
                perror("malloc failed");
                exit(EXIT_FAILURE);
        }

        token = strtok(str, TOK_DELIM);
        while (token != NULL)
        {
                tokens[idx] = malloc(strlen(token) + 1);
                if (!tokens[idx])
                {
                        perror("malloc failed");
                        exit(EXIT_FAILURE);
                }

                strcpy(tokens[idx], token);
                idx++;

                token = strtok(NULL, TOK_DELIM);
        }

        tokens[idx] = NULL;
        return tokens;
}
