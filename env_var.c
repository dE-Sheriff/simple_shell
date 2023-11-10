#include "shell.h"

/**
 * _getenv - a function that gets an environment variable
 * @name: the name of the environment variable to get
 * Return: 0
 */

char *_getenv(const char *name)
{
	extern char **env_var;
	int i = 0;
	char *env_token;

	while (env_var[i])
	{
		env_token = strtok(env_var[i], "=");
		if (_strcmp(env_token, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return (NULL);
}
