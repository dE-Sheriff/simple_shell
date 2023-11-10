#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @sptr: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **sptr)
{
	char *cmd = NULL, *a_cmd;

	if (sptr)
	{
		cmd = sptr[0];
		a_cmd = _get_cpath(cmd);
		if (execve(a_cmd, sptr, NULL) == -1)
			perror("Error: execve failed");
	}
}
