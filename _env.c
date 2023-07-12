#include "main.h"

/**
 * _env - prints the current environment
 *
 * Return: (no return)
 *
 */
void _env(void)
{
<<<<<<< HEAD
	int i = 0;

	while (environ[i] != NULL)
	{
	size_t len = 0;

	while (environ[i][len] != '\0')
	len++;

	write(STDOUT_FILENO, environ[i], len);
	write(STDOUT_FILENO, "\n", 1);
	i++;
	}
=======
        int i = 0;

        while (environ[i] != NULL)
        {
                size_t len = 0;

                while (environ[i][len] != '\0')
                len++;

                write(STDOUT_FILENO, environ[i], len);
                write(STDOUT_FILENO, "\n", 1);
                i++;
        }
>>>>>>> 5db307598998b3bc92b11c6bdb5185edae3b5aa5
}
