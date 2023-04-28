#include "simple_shell.h"
/**
 * execute - execute a command
 * @args: array of arguments
 * Return: 0 on success, -1 on failure
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (1);

	if (strcmp(args[0], "exit") == 0)
		return	(-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		return (-1);
	}
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("%s:command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
