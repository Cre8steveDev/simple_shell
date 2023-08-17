#include <stdlib.h>
#include <stddef.h>

/*
 * THIS FILE CONTAINS STRING FUNCTIONS
 * 1. strcat - Concatenates two strings together src to dest
 * 2. str_concat - Concatenates two strings together. Takes care of allocating
 *               memory for the old string and new string size.
 *               you'll probably free str1 when done.
 * 3. strchr - Checks for a character in a string and returns a pointer
 *               to its first occurence
 * 4. strcmp - compares if two strings are a match returns 0 if yes
 * 5. strcpy - Copies all bytes of src to dest (string)
 */

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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
