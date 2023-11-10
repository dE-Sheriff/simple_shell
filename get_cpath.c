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

	pth = _getenv("PATH");

	if (pth)
	{
		pth_copy = strdup(pth);
		/* Get lengt of the command that as passed */
		cmd_len = kstrlen(cmd);
		/*down the path variable and get all the directory available*/
		pth_token = strtok(pth_copy, ":");

		while (pth_token != NULL)
		{
			dir_len = kstrlen(pth_token);
			file_pth = malloc(cmd_len + dir_len + 2);

			kstrcpy(pth_token, file_pth);
			strcat(file_pth, "/");
			strcat(file_pth, cmd);
			strcat(file_pth, "\0");
			/*testing if the file path actually exists*/
		}
}
