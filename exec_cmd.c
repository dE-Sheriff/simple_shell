#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @sptr: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **sptr)
{
	const char *cmd = NULL;

	if (sptr)
	{
		cmd = sptr[0];
		if (execve(cmd, sptr, NULL) == -1)
			perror("Error: execve failed");
	}
}
