#include "main.h"

/**
 * _cd - implements the builtin cd command
 *
 * @directory: the current directory
 *
 * Return: (no return)
 *
 */
void _cd(const char *directory)
{
	const char *new_directory;
	const char *old_directory;
	char *old_directory_copy;

	if (directory == NULL || directory[0] == '\0')
	{
	new_directory = _getenv("HOME");

	if (new_directory == NULL)
		{
		perror("cd: HOME environment variable not set");
		return;
		}
	}
	else if (_strcmp(directory, "-") == 0)
	{
	old_directory = _getenv("OLDPWD");

	if (old_directory == NULL)
		{
		perror("cd: OLDPWD environment variable not set");
		return;
		}
	new_directory = old_directory;
	}
	else
	{
	new_directory = directory;
	}
	old_directory = _getenv("PWD");

	if (old_directory == NULL)
	{
	perror("cd: PWD environment variable not set");
	return;
	}
	if (chdir(new_directory) == -1)
	{
	perror("cd");
	return;
	}
	if (_setenv("OLDPWD", old_directory, 1) == -1)
	{
	perror("cd: Failed to update OLDPWD environment variable");
	return;
	}
	old_directory_copy = _strdup(old_directory);

	if (old_directory_copy == NULL)
	{
	perror("cd: Failed to allocate memory");
	return;
	}
	if (_setenv("PWD", new_directory, 1) == -1)
	{
	perror("cd: Failed to update PWD environment variable");
	free(old_directory_copy);
	return;
	}
	free(old_directory_copy);
}
