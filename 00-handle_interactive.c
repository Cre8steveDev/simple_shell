#include "shell.h"

/**
 * handle_interactive - Function that handles the interactive mode
 * @env: Environment variable received from main
 * Return: Void
 */
/**SUBJECT TO MODIFICATION IN NON-INTERACTIVE MODE*/
void handle_interactive_mode(char **argv, char **env)
{
	char **token_array = process_input(argv);
	pid_t pid_val;
	int execve_val;

	if ((pid_val = fork()) == -1)
		free_array_tokens(token_array),
			perror(argv[0]),
			exit(EXIT_FAILURE);
	else if (pid_val == 0)
	{
		if ((execve_val = execve(token_array[0], token_array, env)) == -1)
			free_array_tokens(token_array),
				perror(argv[0]), exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	free_array_tokens(token_array);
	return;
}
