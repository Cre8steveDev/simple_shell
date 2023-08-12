#include "shell.h"

/**
 * main - A program that emulates the Thompson Shell.
 * @argc: Argument Counter
 * @argv: Argument Variables - Null-terminated array of strings
 * @env: Environment variables
 * Return: Always (0) on success
 */

int main(int argc, char **argv, char **env)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			write(1, "$ ", 2);
			handle_interactive_mode(argv, env);
		}
	}
	else
	{
		handle_non_interactive_mode(argv, env);
	}

	return (0);
}

/**
 * free_array_tokens - frees an array of strings
 * @array_tokens: Argument pointer to grid to be freed
 * Return: Always Void;
 */

void free_array_tokens(char **array_tokens)
{
	int i = 0;

	while (array_tokens[i] != NULL)
	{
		free(array_tokens[i]);
		i++;
	}

	free(array_tokens);
}
