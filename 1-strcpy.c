/**
 * _strcpy - Returns the number of elements in a string
 * @dest: Destination
 * @src: Source
 * Return: dest (Success)
 */

char *_strcpy(char *dest, char *src)
{
	char *start_d = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (start_d);

	/**/
}
