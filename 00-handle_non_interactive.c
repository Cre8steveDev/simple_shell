#include "shell.h"
#include <stdio.h>

/**
 * handle_non_interactive - Function that handles the interactive mode
 * @env: Environment variable received from main
 * Return: Void
 */

void handle_non_interactive_mode(char **argv, char **env)
{
    char **token_array = process_input(argv, env);
    pid_t pid_val;
    int execve_val;

    if ((pid_val = fork()) == -1)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (pid_val == 0)
    {
        if ((execve_val = execve(token_array[0], token_array, env)) == -1)
        {
            free_array_tokens(token_array);
            perror(argv[0]), exit(EXIT_FAILURE);
        }
    }
    else
        wait(NULL);

    free_array_tokens(token_array);
    return;
}

char **process_input(char **argv, char **env)
{
    char *path_variable = NULL, *user_string = NULL, *token = NULL;
    char **token_array = NULL;
    ssize_t string_read;
    size_t stringBuffSize = 0;
    pid_t pid_val;
    int execve_val;

    string_read = getline(&user_string, &stringBuffSize, stdin);
    if (string_read < 0)
        free(user_string), perror(argv[0]),
            exit(EXIT_FAILURE);
    token_array = split_user_input(user_string);
    // Modify split_user function to free token array when it fails
    if (token_array == NULL)
    {
        free_array_tokens(token_array);
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    free(user_string);
    return (token_array);
}
