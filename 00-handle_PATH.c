#include "shell.h"

/**
 * handle_PATH - handles when a command name is passed
 * @argv: Commandline argument passed in for program name
 * @env: Environment variables
 * @token_array: For command and argument
 * @cmd_count: Command count variable pointer (unused now)
 * Return: Returns -1 if it fails or 0 if it succeeds
 */

int handle_PATH(char **argv, char **env, char **token_array, int *cmd_count)
{
	char **paths_array = split_path(get_path(env)), *full_path;
	int i = 0, len_str, execve_val, status = -1;
	pid_t pid_val;

	(void)cmd_count;
	if (paths_array == NULL)
		return (-1);

	while (paths_array[i])
	{
		len_str = _strlen(paths_array[i]) + _strlen(token_array[0]) + 2;
		full_path = malloc(len_str);
		_strcpy(full_path, paths_array[i]);
		_strcat(full_path, "/");
		_strcat(full_path, token_array[0]);
		if (access(full_path, F_OK) == -1)
		{
			free(full_path), i++, errno = 127;
			continue;
		}
		else
		{
			status = 1, pid_val = fork();
			if (pid_val == -1)
				return (-1);
			else if (pid_val == 0)
			{
				execve_val = execve(full_path, token_array, env);
				if (execve_val == -1)
					perror(argv[0]), exit(EXIT_FAILURE);
			}
			else
				wait(&status), free(full_path), errno = status;
			break;
		}
	}
	free_array_tokens(paths_array);
	return (status);
}
