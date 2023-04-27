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
    char **args = NULL;
    char *prompt = "~$";
    char *username = getlogin();
    char *uinput = NULL;
    int exstatus; /* variable to hold execution status */
    (void)ac;
    (void)argv;

    /*prompt loop*/
    while (1)
    {
        printf("%s%s", username, prompt);
        uinput = read_input();
        if (uinput == NULL)
        {
            printf("\n");
            break;
        }
        args = tokenize(uinput);
        if (strcmp(args[0], "exit") == 0)
        {
            printf("\n Exiting Nadrian...Bye bye \n");
            free_array(args);
            free(uinput);
            return (0);
        }
        exstatus = execute(args);
        if (exstatus == -1)
        {
            break;
        }
        free_array(args);
        free(uinput);
        args = NULL;
        uinput = NULL;
    }

    free_array(args);
    free(uinput);
    return (0);
}

