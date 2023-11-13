#include "shell.h"

/**
 * _getenv - a function that gets an environment variable
 * @name: the name of the environment variable to get
 * Return: 0
 */

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *env_token;

	while (environ[i])
	{
		env_token = strtok(environ[i], "=");
		if (_strcmp(env_token, (char *)name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return (NULL);
}
