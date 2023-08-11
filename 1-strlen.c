/**
 * _strlen - Returns the number of elements in a string
 * @s: String argument to be counted
 * Return: Always Sum (Success)
 */

int _strlen(char *s)
{
	int length = 0;
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		length += 1;
	}

	return (length);
}
