#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

/*Custom String Function Prototypes*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/*Memory Allocation Prototypes*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*User-defined Prototypes*/

#endif /*SHELL_H*/
