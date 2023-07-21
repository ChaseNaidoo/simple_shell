#include "main.h"

/**
 * _getenv - Emulates getenv
 *
 * @name: String representing the environment variable name
 *
 * Return: Pointer to the value of the environment variable (Success), NULL (Failure)
 *
 */
char *_getenv(const char *name)
{
	int i;

	if (name == NULL || name[0] == '\0')
	return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
	char *env_var = environ[i];
	int j = 0;

	while (env_var[j] != '=' && env_var[j] != '\0')
	j++;

	if (j > 0 && _strncmp(env_var, name, j) == 0 && env_var[j] == '=')
	return (&env_var[j + 1]);
	}
	return (NULL);
}
