#include "shell.h"
/**
 * process_input - processes user input, splits into tokens and
 * returns an array of strings to the caller
 * @argv: Commandline argument for name of program
 */
char **process_input(char **argv)
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
