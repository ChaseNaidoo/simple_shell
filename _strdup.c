#include "main.h"

/**
 * _strdup - duplicates a string
 *
 * @str: string to be duplicated
 *
 * Return: a pointer to the duplicated string, no memory (NULL)
 *
 */
char *_strdup(const char *str)
{
	char *s;
	char *p;
	int len = 0;

	if (str == NULL)
	{
	return (NULL);
	}

	while (str[len])
	len++;
	s = malloc(len + 1);

	if (s == NULL)
	{
	return (NULL):
	}

	p = s;

	while (*str)
	*p++ = *str++;
	*p = '\0';

	return (s);
}
