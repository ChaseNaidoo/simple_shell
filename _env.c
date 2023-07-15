#include "main.h"

/**
 * _env - prints the current environment
 *
 * Return: (no return)
 */
void _env(void)
{
  int num_env = 0;
  int i;
  char **env_vars;
  
  while (environ[num_env] != NULL)
    {
      num_env++;
    }

  env_vars = malloc(num_env * sizeof(char *));
  if (env_vars == NULL)
    {
      perror("Memory allocation failed.\n");
      return;
    }

  for (i = 0; i < num_env; i++)
    {
      env_vars[i] = environ[i];
    }

  for (i = num_env - 1; i >= 0; i--)
    {
      size_t len = 0;
      while (env_vars[i][len] != '\0')
	len++;

      write(STDOUT_FILENO, env_vars[i], len);
      write(STDOUT_FILENO, "\n", 1);
    }

  free(env_vars);
}
