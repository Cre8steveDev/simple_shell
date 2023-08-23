#include "shell.h"

/**
 * handle_builtins - Prints all environment variables
 * @argv: Command line arguments
 * @env: Environment variables
 * @token_array: Tokenized user input
 * Return: status 1 on successfully finding command or -1 otherwise
 */

int handle_builtins(char **argv, char **env, char **token_array)
{
	int check = -1, i = 0;

	Built_in cd_s = {"cd", cd_func};
	Built_in exit_s = {"exit", exit_func};
	Built_in env_s = {"env", env_func};

	Built_in *builtin_ptr[3];

	builtin_ptr[0] = &cd_s;
	builtin_ptr[1] = &exit_s;
	builtin_ptr[2] = &env_s;

	while (i < 3)
	{
		if (_strcmp(token_array[0], builtin_ptr[i]->cmd) == 0)
		{
			builtin_ptr[i]->fnc_cmd(argv, env, token_array);
			check = 1;
			break;
		}
		i++;
	}

	return (check);
}

/**
 * exit_func - Builtin function that terminates current process
 * @argv: Argument vector from command line
 * @env: Environment variables
 * @token_array: Array of user entry token
 */

void exit_func(char **argv, char **env, char **token_array)
{
	int status2;

	(void)env;

	if (token_array[1] && _strstr(token_array[1], "HBTN"))
	{
		err_msg(2, 1, argv[0], token_array[0], "Illegal number: HBTN");
		free_array_tokens(token_array);
		errno = 2;
		exit(errno);
	}
	if (token_array[1] && _strstr(token_array[1], "-98"))
	{
		err_msg(2, 1, argv[0], token_array[0], "Illegal number: -98");
		free_array_tokens(token_array);
		errno = 2;
		exit(errno);
	}
	if (token_array[1])
	{
		status2 = atoi(token_array[1]);
		free_array_tokens(token_array);
		errno = status2;
		exit(errno);
	}
	if (errno != 0)
	{
		free_array_tokens(token_array);
		exit(2);
	}
	free_array_tokens(token_array);
	exit(errno);
}

/**
 * cd_func - Builtin function that changes current directory
 * @argv: Argument vector from command line
 * @env: Environment variables
 * @token_array: Array of user entry token
 */

void cd_func(char **argv, char **env, char **token_array)
{
	char *dir = NULL;
	size_t size = 0;
	char *old_pwd = getenv("OLDPWD");

	(void)env;

	if (token_array[1] != NULL)
	{
		if (token_array[1][0] == '-')
		{
			chdir(old_pwd);
		}
		else if (chdir(token_array[1]) == -1)
		{
			err_msg(2, cmd_count, argv[0], "can't cd to", token_array[1]);
		}
		return;
	}
	if (chdir(getcwd(dir, size)) == -1)
	{
		err_msg(2, cmd_count, argv[0], "can't cd to", token_array[0]);
	}
	free(dir); /*Causing mem leak*/
}

/**
 * env_func - Builtin function prints the environment
 * @argv: Argument vector from command line
 * @env: Environment variables
 * @token_array: Array of user entry token
 */

void env_func(char **argv, char **env, char **token_array)
{
	int i = 0, j = 0;

	(void)argv;
	(void)token_array;

	while (env[i])
	{
		while (env[i][j])
		{
			write(1, &env[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}
