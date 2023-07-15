#include "main.h"

/**
 * _env - prints the current environment
 *
 * Return: (no return)
 *
 */
void _env(void)
{
    int i = 0;
    int num_env = 0;

    while (environ[num_env] != NULL)
    {
        num_env++;
    }

    char *env_vars[num_env];

    i = 0;
    while (environ[i] != NULL)
    {
        env_vars[i] = environ[i];
        i++;
    }

    i = num_env - 1;
    while (i >= 0)
    {
        size_t len = 0;

        while (env_vars[i][len] != '\0')
            len++;

        write(STDOUT_FILENO, env_vars[i], len);
        write(STDOUT_FILENO, "\n", 1);
        i--;
    }
}
