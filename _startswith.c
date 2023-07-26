#include "main.h"

/**
 * _startswith - Check if a string starts with a given prefix
 *
 * @str: The string to check
 * @prefix: The prefix to compare with
 *
 * Return: 1 if the string starts with the prefix, 0 otherwise
 */
int _startswith(const char *str, const char *prefix)
{
	while (*prefix)
	{
	if (*str != *prefix)
	return (0);
	str++;
	prefix++;
	}
	return (1);
}
