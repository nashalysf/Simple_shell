#include "simple_shell.h"
/**
 * forks - creates child process
 * @find: finds command to execute
 * @argv: array of args
 * @counter: amount of input lines
 * Return: exit status of child
 */
int forks(char *find, char **argv, size_t *counter)
{
	int status;
	pid_t pid_child = fork();

	if (pid_child == -1)
		return (0);
	counter++;
	if (pid_child == 0)
		execute(argv);
	if (strcmp(argv[0], find) != 0)
		free(find);
	free(argv);
	wait(&status);

	return (WEXITSTATUS(status));

}
/**
 * path - finds file in dir
 * @file_name: file name
 * @dir: directory
 * Return: 0. for success -1. for failure
 */
int path(const char *file_name, DIR *dir)
{
	struct dirent *dr;
	int success = -1;

	while ((dr = readdir(dir)) != NULL)
	{
		if (dr->d_type == DT_REG && strcmp(dr->d_name, file_name) == 0)
		{
			success = 0;
			break;
		}
	}
	return (success);
}
