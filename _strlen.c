#include "main.h"

/**
 * _strlen - entry point
 *
 * @s: input character
 *
 * Return: the length of the string
 *
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
	i++;
	}
	return (i);
}
