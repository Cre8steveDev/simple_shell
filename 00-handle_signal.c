#include "shell.h"

/**
 * handle_signal - Handles the CTRL + C signal
 * @signum: Number returned from call to Signal
 * Return: Returns Void
 */

void handle_signal(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	write(1, "$ ", 2);
}
