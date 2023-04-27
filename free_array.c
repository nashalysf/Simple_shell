#include "simple_shell.h"
/**
 * args- arguments to free
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

