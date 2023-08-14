#include "shell.h"

/**
 * handle_interactions - Function that handles the interactive mode
 * @argv: Argument vector for program name or command line arg
 * @env: Environment variable received from main
 * @cmd_count: Keeps track of how many commands entered
 * Return: Void
 */

/**SUBJECT TO MODIFICATION IN NON-INTERACTIVE MODE*/
void handle_interactions(char **argv, char **env, int *cmd_count)
{
	char **token_array = process_input(argv);
	pid_t pid_val;
	int execve_val;

	if (token_array[0] == NULL || token_array == NULL)
	{
		free(token_array[0]), free_array_tokens(token_array);
		return;
	}
	/*
	 * Tests if token 0 is any of the builtins then returns 0 or 1 for no or yes.
	 * if (handle_builtins(argv, env, token_array)) return;
	 */
	if (access(token_array[0], F_OK) == -1)
	{
		if (handle_PATH(argv, env, token_array, cmd_count) == -1)
		{
			err_msg(2, *cmd_count, argv[0], token_array[0], "not found");
			free_array_tokens(token_array);
			return; /*exit(EXIT_SUCCESS);*/
		}
		return;
	}
	else
		pid_val = fork();

	if (pid_val == -1)
		free_array_tokens(token_array), perror(argv[0]),
			exit(EXIT_FAILURE);
	else if (pid_val == 0)
	{
		execve_val = execve(token_array[0], token_array, env);
		if (execve_val == -1)
			free_array_tokens(token_array),
				perror(argv[0]), exit(EXIT_FAILURE);
	}
	else
		wait(NULL), free_array_tokens(token_array);
}
