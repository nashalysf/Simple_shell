#include "simple_shell.h"
/**
 * execute - execute a command
 * @args: array of arguments
 * @envp: environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute(char **args)
{
	pid_t pid = fork();
	int status;

    if (pid < 0) {
        perror("fork");
        return (-1);
    }

    if (pid == 0) {
        execvp(args[0], args);
        perror(args[0]);
        exit(EXIT_FAILURE);
    }

    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        return (-1);
    }

    return (0);
}
