#include "main.h"

/**
<<<<<<< HEAD
 * _getenv - emulates getenv function
 *
 * @name:string argument representing environ array
 *
 * Return: pointer to value of environ (success), NULL (fail)
 *
 */
char *_getenv(const char *name)
{
	size_t name_len;
	int i;
	char *env_var;
	size_t equals_pos;

	if (name == NULL || name[0] == '\0')
	return (NULL);

	name_len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
	env_var = environ[i];
	equals_pos = 0;

	while (env_var[equals_pos] != '=' && env_var[equals_pos] != '\0')
	equals_pos++;

	if (equals_pos > 0 && equals_pos == name_len && _strlen(env_var, name, (size_t) equals_pos) == 0)
	return (env_var + equals + 1);
	}
	return (NULL);
=======
 * _getenv - Emulates getenv
 *
 * @name: String argument representing environ array
 *
 * Return: Pointer to valueof environ (Success), NULL (Failure)
 */
char *_getenv(const char *name)
{
        size_t name_len;
        int i;
        char *env_var;
        size_t equals_pos;

        if (name == NULL || name[0] == '\0')
        return (NULL);

        name_len = _strlen(name);

        for (i = 0; environ[i] != NULL; i++)
        {
        env_var = environ[i];
        equals_pos = 0;

        while (env_var[equals_pos] != '=' && env_var[equals_pos] != '\0')
        equals_pos++;

        if (equals_pos > 0 && equals_pos == name_len && _strncmp(env_var, name, (size_t) equals_pos) == 0)
        return (env_var + equals_pos + 1);
        }
        return (NULL);
>>>>>>> 5db307598998b3bc92b11c6bdb5185edae3b5aa5
}
