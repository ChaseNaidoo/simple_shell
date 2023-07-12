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

        if (name == NULL || name[0] == '\0')
        {
        write(STDERR_FILENO, "unsetenv: Invalid command syntax\n", 33);
        return (-1);
        }
        result = unsetenv(name);

        if (result != 0)
        {
        write(STDERR_FILENO, "unsetenv: Failed to unset environment variable\n", 48);
        return (-1);
        }
        return (0);
}
