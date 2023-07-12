#include "main.h"

/**
 * _setenv - emulates setenv function
 *
 * @name: string representing environment variable
 * @value: value to be assigned to environment variable
 * @overwrite: integer flag for overwriting variables
 *
 * Return: 0 (success), -1 (error)
 *
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int result;

	if (name == NULL || value == NULL || name[0] == '\0' || value[0] == '\0')
	{
	write(STDERR_FILENO, "setenv: Invalid command syntax\n", 31);
	return (-1);
	}
	result = _setenv(name, value, overwrite);

	if (result != 0)
	{
	write(STDERR_FILENO, "setenv: Failed to set environment vaiable\n", 43);
	return (-1);
	}
	return (0);
}
