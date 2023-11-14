#include "shell.h"

/**
 * _get_cpath - get location of our command path
 * @cmd: name of path to check for
 * Return: string of path
 */

char *_get_cpath(char *cmd)
{
	char *pth, *pth_copy, *pth_token, *file_pth;
	int cmd_len, dir_len;
	struct stat buffer;

	pth = getenv("PATH");
	if (pth)
	{
		pth_copy = _strdup(pth);
		/* Get lengt of the command that as passed */
		cmd_len = _strlen(cmd);
		/*down the path variable and get all the directory available*/
		pth_token = strtok(pth_copy, ":");
		while (pth_token != NULL)
		{
			dir_len = _strlen(pth_token);
			file_pth = malloc(cmd_len + dir_len + 2);
			_strcpy(file_pth, pth_token);
			_strcat(file_pth, "/");
			_strcat(file_pth, cmd);
			_strcat(file_pth, "\0");
			/*testing if the file path actually exists*/
			if (stat(file_pth, &buffer) == 0)
			{
				free(pth_copy);
				return (file_pth);
			}
			else
			{
				free(file_pth);
				pth_token = strtok(NULL, ":");
			}
		}
		free(pth_copy);
		if (stat(cmd, &buffer) != -1)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
