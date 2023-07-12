#include "main.h"

/**
 * _strncpy - copies n characters from the string
 *
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 * @n: number of characters to be copied
 *
 * Return: pointer to the destination buffer
 *
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_start = dest;
	size_t i;

	for (i = 0; i < n; i++)
	{
	if (src[i] != '\0')

	dest[i] = src[i];
	else
	break;
	}
	for (; i < n; i++)
	{
	dest[i] = '\0';
	}
	return (dest_start);
}
