#include "shell.h"
#include <stdio.h>

/**
 * handle_non_interactive_mode - Function that handles the interactive mode
 * @argv: Argument from command line with program name
 * @env: Environment variable received from main
 * Return: Void
 */

void handle_non_interactive_mode(char **argv, char **env)
{
	char **token_array = process_input(argv);
	pid_t pid_val;
	int execve_val;

	pid_val = fork();
	if (pid_val == -1)
		free_array_tokens(token_array),
			perror(argv[0]),
			exit(EXIT_FAILURE);
	else if (pid_val == 0)
	{
		execve(token_array[0], token_array, env);
		if (execve_val == -1)
			free_array_tokens(token_array),
				perror(argv[0]), exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	free_array_tokens(token_array);
}
