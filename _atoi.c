#include "main.h"

/**
 * _atoi - Entry point
 *
 * @s: input character s
 *
 * Return: (result), 0 (no numbers)
 *
 */
int _atoi(char *s)
{
	unsigned int result = 0;
	int i = 0;
	int sign = 1;

	if (s[0] == '-')
	{
	sign = -1;
	i++;
	}
	for (; s[i] != '\0'; i++)
	{
	if (s[i] < '0' || s[i] > '9')
		{
		return (0);
		}
	result = result * 10 + (s[i] - '0');
	}
	return (sign * result);
}
