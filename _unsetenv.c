#include "main.h"

/**
 * _unsetenv - Emulates unsetenv
 *
 * @name: String representing environment variable to unset
 *
 * Return: 0 (success), -1 (error)
 */
int _unsetenv(const char *name)
{
	int result;
	char *env_val;

	if (name == NULL || name[0] == '\0')
	{
	write(STDERR_FILENO, "unsetenv: Invalid command syntax\n", 33);
	return (-1);
	}

	env_val = _getenv(name);

	if (env_val == NULL)
	{
	write(STDERR_FILENO, "unsetenv: Variable not found\n", 29);
	return (-1);
	}
	result = unsetenv(name);

	if (result != 0)
	{
	write(STDERR_FILENO, "unsetenv: Failed to unset environment variable\n", 45);
	return (-1);
	}
	return (0);
}
