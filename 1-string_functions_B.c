#include <stddef.h>
#include <stdlib.h>

/*
 * THIS FILE CONTAINS STRING FUNCTIONS
 * 1. strstr - Checks for a substring withing a string
 * 2. strncpy - Copies n bytes from one string to the dest
 * 3. strncat - Concatenates n bytes from src to dest (space must be
 *               allocated in advance for the new concatenation
 *               and the null byte)
 * 4. strlen - Counts the number of bytes in a string
 * 5. strdup - Duplicates one string into another address (mallocs)
 */

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}

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

/**
 * _strdup - copies the string given as parameter
 * @str: string to duplicate
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */

char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = str[i]) != '\0')
		i++;

	return (dup);
}
