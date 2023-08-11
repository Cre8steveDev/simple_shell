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
	int tweak;

	tweak = printf("Hello World!\n");

	if (tweak > 0)
	{
		perror("error occured");
		return (EXIT_FAILURE);
	}

	return (0);
}
