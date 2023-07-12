#include "main.h"

/**
 * find_command_path - finds the full path of the command
 *
 * @path_env: PATH environment variable
 * @command: command to search for
 *
 * Return: pointer to the full path of the command
 */
char *find_command_path(char *path_env, char *command)
{
        char *path_env_copy = _strdup(path_env);
        char *path;
        char *command_path = NULL;
        struct stat st;
        int path_allocated = 0;

        if (path_env == NULL || command == NULL)
        {
        return (NULL);
        }
        path = strtok(path_env_copy, ":");

        while (path != NULL)
        {
        int path_length = _strlen(path);
        int command_length = _strlen(command);

        command_path = malloc((path_length + 1 + command_length + 1) * sizeof(char));

        if (command_path == NULL)
        {
        perror("Memory allocation failed.\n");
        free(path_env_copy);
        return (NULL);
        }
        _strcpy(command_path, path);
        _strcat(command_path, "/");
        _strcat(command_path, command);

        if (stat(command_path, &st) == 0 && S_ISREG(st.st_mode) && st.st_mode & S_IXUSR)
        {
        path_allocated = 1;
        break;
        }
        free(command_path);
        command_path = NULL;
        path = strtok(NULL, ":");
        }
        free(path_env_copy);

        if (!path_allocated)
        {
        free(command_path);
        command_path = NULL;
        }
        return (command_path);
}
