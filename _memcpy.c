#include "main.h"

/**
 * _memcpy - Emulates memcpy
 *
 * @dest: Destination memory location
 * @src: Source memory location
 * @n: Number of bytes to copy
 *
 * Return: (no return)
 *
 */
void _memcpy(void *dest, const void *src, size_t n)
{
	const char *src_ptr = src;
	char *dest_ptr = dest;
	ssize_t bytes_written;

	while (n > 0)
	{
	bytes_written = write(STDOUT_FILENO, src_ptr, n);

	if (bytes_written == -1)
	{
	perror("Error writing to stdout");
	return;
	}
	src_ptr += bytes_written;
	dest_ptr += bytes_written;
	n -= bytes_written;
	}
}
