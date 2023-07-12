#include "main.h"

/**
 * _strcat - concatenates two strings
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the destination string
 *
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;

	while (*dest_ptr != '\0')
	{
	dest_ptr++;
	}
	while (*src != '\0')
	{
	*dest_ptr = *src;
	dest_ptr++;
	src++;
	}
	*dest_ptr = '\0';
	return (dest);
}
