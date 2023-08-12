#include "shell.h"

/**
 * handle_builtins - Prints all environment variables
 * @argv: Command line arguments
 * @env: Environment variables
 * @token_array: Tokenized user input
 * Return: status 1 on successfully finding command or 0 otherwise
 */

int handle_builtins(char **argv, char **env, char **token_array)
{
	int status = 0;

	/**
	 * Check if token_array[0] matches any of the
	 * implemented builtins cd, env, exit
	 * And call the appropriate function to handle the command
	 *  then set status to 1.
	 */

	return (status);
}
