#include <stdlib.h>
#include "shell.h"

/**
 * get_path - Returns a pointer to the path variable
 * from the environmental variables of the system
 * @env: Environmental Variable
 * Return: Char *pointer to the paths
 */

char *get_path(char **env)
{
	char *path = NULL;
	int i = 0;

	while (env[i])
	{
		if (_strstr(env[i], "PATH") && env[i][0] == 'P' && env[i][4] == '=')
		{
			path = env[i];
			break;
		}
		i++;
	}
	if (path != NULL)
	{
		for (i = 0; i < 6; i++)
			path++;
	}

	return (path);
}
