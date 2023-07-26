#include "main.h"

/**
 * _setenv - Emulates setenv
 *
 * @name: String representing environment variable
 * @value: Value to be assigned to environment variable
 * @overwrite: Integer flag for overwriting variables
 *
 * Return: 0 (success), -1 (error)
 */
int _setenv(const char *name, const char *value, int overwrite)
{
  int result;
  char *env_val;
  
  if (name == NULL || value == NULL || name[0] == '\0' || value[0] == '\0')
    {
      write(STDERR_FILENO, "setenv: Invalid command syntax\n", 31);
      return (-1);
    }

  if (overwrite == 0)
    {
      env_val = _getenv(name);
      if (env_val != NULL)
	{
	  write(STDERR_FILENO, "setenv: Variable already exists. Use setenv with overwrite=1 to modify.\n", 73);
	  return (-1);
	}
    }

  result = setenv(name, value, overwrite);

  if (result != 0)
    {
      write(STDERR_FILENO, "setenv: Failed to set environment variable\n", 43);
      return (-1);
    }

  return (0);
}
