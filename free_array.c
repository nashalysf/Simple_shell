#include "simple_shell.h"
/**
 * args- arguments to free
 */
void free_array(char **args)
{
	int c = 0;

	while (args[c])
	{
		free(args[c]);
		c++;
	}
	free(args);
}

