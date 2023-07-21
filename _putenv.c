#include "main.h"

/**
 * _putenv - Emulates putenv
 *
 * @string: String representing environ variable
 *
 * Return: 0 (Success), 1 (Failure)
 *
 */
int _putenv(char *string)
{
	char *name, *value, *env_var, **new_environ;
	int num_vars, new_size, i;

	if (string == NULL || string[0] == '\0')
	{
	return (-1);
	}
	name = strtok(string, "=");
	value = strtok(NULL, "");

	if (name == NULL || value == NULL)
	{
	return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
	env_var = environ[i];

	if (_strncmp(env_var, name, _strlen(name)) == 0)
		{
		environ[i] = string;
		return (0);
		}
	}
	num_vars = i;
	new_size = num_vars + 2;
	new_environ = malloc(new_size * sizeof(char *));

	if (new_environ == NULL)
	{
	return (-1);
	}
	for (i = 0; i < num_vars; i++)
	{
	new_environ[i] = environ[i];
	}
	new_environ[num_vars] = string;
	new_environ[num_vars + 1] = NULL;
	environ = new_environ;
	return (0);
}
