#include "simple_shell.h"
/**
 * execute - execute a command
 * @args: array of arguments
 * Return: 0 on success, -1 on failure
 */
int execute(char **args)
{
	pid_t pid;/*process ID*/
	int status;/*process status*/

	if (args[0] == NULL)
		return (1);

	/*if the first argument is "exit" return -1 end exit the shell*/
	if (strcmp(args[0], "exit") == 0)
		return	(-1);

	pid = fork();/*create a new process*/
	if (pid == -1)/*check for errors in creating new process*/
	{
		perror("Fork error");
		return (-1);
	}
	if (pid == 0)/*if in the child process*/
	{
		if (execvp(args[0], args) == -1)/*execute the command*/
		{
			/*print error message if command not found*/
			printf("%s:command not found\n", args[0]);
			exit(EXIT_FAILURE);/*exit child process if command execution fails*/
		}
	}
	else/*if in the parent process*/
	{
		do {
			waitpid(pid, &status, WUNTRACED);/*wait for child process to finish*/
			/*check for process status*/
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);/*return success*/
}
