#include "main.h"
#include <unistd.h>

/**
 * get_path_env - retrieves the value of the PATH environment variable
 *
 * Return: pointer to the PATH environment variable string
 *
 */
char *get_path_env(void)
{
        int i;
        char *path_env = NULL;
        char *path_env_copy;

        for (i = 0; environ[i] != NULL; i++)
        {
        if (_strncmp(environ[i], "PATH=", 5) == 0)
                {
                path_env = environ[i] + 5;
                break;
                }
        }
        if (path_env == NULL)
        {
        return (NULL);
        }
        path_env_copy = _strdup(path_env);

        if (path_env_copy == NULL)
        {
        return (NULL);
        }
        return (path_env_copy);
}
