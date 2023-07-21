#include "main.h"

/**
 * find_command_path - finds the full path of the command
 *
 * @command: command to search for
 *
 * Return: pointer to the full path of the command, or NULL if not found
 *
 */
char *find_command_path(const char *command)
{
	char *path_env = _getenv("PATH");
	char *path;
	char *command_path;
	char *path_env_copy;

	if (path_env == NULL || command == NULL)
	return (NULL);

	path_env_copy = _strdup(path_env);
	if (path_env_copy == NULL)
	{
	perror("Memory allocation failed.\n");
	return (NULL);
	}
	path = strtok(path_env_copy, ":");
	command_path = NULL;
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
	if (access(command_path, X_OK) == 0)
	break;

	free(command_path);
	command_path = NULL;
	path = strtok(NULL, ":");
	}
	free(path_env_copy);
	return (command_path);
}
