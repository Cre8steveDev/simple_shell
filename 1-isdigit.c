#include "shell.h"

/**
 * _isdigit - Function checks if char is between/= 0 to 9
 * @c: Only parameter in function
 * Return: Returns 1 if true 0 if false
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
