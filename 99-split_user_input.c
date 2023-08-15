#include "shell.h"

/**
 * split_user_input - Splits the user input into tokens
 * and returns a pointer to a dynamically allocated array
 * of strings - NULL terminated
 * @user_input: String of user input delimited by " \n\t\r" to be plit
 * Return: On Success array of strings char ** or NULL on fail
 */

char **split_user_input(char *user_input)
{
	char **token_array = NULL;
	int token_num = 0, i = 0;
	char *temp_path = _strdup(user_input), *temp_tok;
	char *DELIM = " \"\n\t\r";

	if (temp_path != NULL)
	{
		temp_tok = strtok(temp_path, DELIM);
		while (temp_tok != NULL)
			token_num++, temp_tok = strtok(NULL, DELIM);
	}
	/* Increment token_num by one to account for NULL terminating string */
	token_num++;
	token_array = malloc(sizeof(char *) * token_num);
	if (token_array == NULL)
	{
		perror("Error allocating memory for tokens.");
		free(temp_path), free(token_array);
		exit(EXIT_FAILURE);
	}

	free(temp_path);
	temp_path = _strdup(user_input);
	temp_tok = strtok(temp_path, DELIM);
	token_array[i] = _strdup(temp_tok);

	while (temp_tok != NULL)
	{
		i++;
		temp_tok = strtok(NULL, DELIM);
		if (temp_tok != NULL)
			token_array[i] = _strdup(temp_tok);
	}
	token_array[i] = NULL;
	free(temp_path);
	return (token_array);
}
