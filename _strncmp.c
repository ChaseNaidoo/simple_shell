#include "main.h"

/**
 * _strncmp - entry point
 *
 * @s1: first input
 * @s2: second input
 * @n: number of characters to compare
 *
 * Return: 0 (s1 = s2), > 0 (s2, s1), < 0 (s1, s2)
 *
 */
int _strncmp(const char *s1, const *s2, size_t n)
{
	while (n > 0 && *s1 && *s1 == *s2)
	{
	s1++;
	s2++;
	n--;
	}
	if (n == 0)
	return (0);
	else
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
