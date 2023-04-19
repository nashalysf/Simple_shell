#include "simple_shell.h"
/**
 *_pwd - prints current working direvtory
 *
 */
void _pwd(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd() error");
	}
	free(cwd);
}
