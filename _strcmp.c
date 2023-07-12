#include "main.h"

/**
 * _strcmp - entry point
 *
 * @s1: first input
 * @s2: second inpput
 *
 * Return: 0 (s1 = s2), > 0 (s2, s1), < 0 (s1, s2)
 *
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}
