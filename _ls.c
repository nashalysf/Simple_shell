#include "simple_shell.h"
/**
 * _ls - print list of files
 */
void _ls(void)
{
	char cwd[1024];
	struct dirent *entry;
	DIR *dir;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return;
	}

	dir = opendir(cwd);
	if (dir == NULL)
	{
		perror("opendir() error");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			printf("%s ", entry->d_name);
		}
	}
	closedir(dir);
	printf("\n");
}
