#include "simple_shell.h"
/**
 * prompt-prints prompt
 */
void prompt(void)
{
	/*Only prints the prompt if running interactively */
	if (isatty(STDIN_FILENO))
	{

		printf("$ ");
	}
}
