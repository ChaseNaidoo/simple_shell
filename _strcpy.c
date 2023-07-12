#include "main.h"

/**
 * _strcpy - copies a string from source to destination
 *
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to the destination buffer
 *
 */
char *_strcpy(char *dest, const char *src)
{
	char *dest_ptr = dest;

	while (*src != '\0')
	{
	*dest_ptr = *src;
	dest_ptr++;
	src++;
	}
	*dest_ptr = '\0';

	return (dest);
}
