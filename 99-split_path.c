#include "shell.h"

/**
 * split_path - Splits the environment variable path
 * and returns a pointer to a dynamically allocated array
 * of strings - NULL terminated
 * @path_var: String of directories delimited by : to be plit
 * Return: On Success array of strings char ** or NULL on fail
 */

char **split_path(char *path_var)
{
	char **token_array = NULL;
	int token_num = 0, i = 0;
	char *temp_path = _strdup(path_var), *temp_tok;
	char *dummy = "Hello";

	if (temp_path != NULL)
	{
		temp_tok = strtok(temp_path, ":");
		while (temp_tok != NULL)
			token_num++, temp_tok = strtok(NULL, ":");
	}
	/* Increment token_num by one to account for NULL terminating string */
	token_num++;
	token_array = malloc(sizeof(char *) * token_num);
	if (token_array == NULL)
	{
		perror("Error allocating memory for tokens.");
		free(temp_path);
		exit(EXIT_FAILURE);
	}
	free(temp_path);

	temp_path = _strdup(path_var);

	temp_tok = strtok(temp_path, ":");
	token_array[i] = _strdup(temp_tok);

	while (temp_tok != NULL)
		i++, temp_tok = strtok(NULL, ":"),
			 token_array[i] = _strdup(temp_tok);

	token_array[i] = NULL;

	free(temp_path);
	return (token_array);
}
