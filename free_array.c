#include "simple_shell.h"
/**
 * free_array - frees malloc
 * @arr: arguments to free
 * Return: void
 */
void free_array(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}

	free(arr);
}
