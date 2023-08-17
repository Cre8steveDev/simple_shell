#include "shell.h"

/**
 * find_str_in_path - finds if a string exists in the path
 * @cmd: Command string to be searched in the path
 * @path: retrieved path variable
 * Return: Pointer to string if it it exists or NULL otherwise
 */

char *find_str_in_path(char *cmd, char *path)
{
	char *result = NULL;

	if (path != NULL)
		result = _strstr(path, cmd);

	return (result);
}
