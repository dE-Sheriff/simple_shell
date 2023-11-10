#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @argv: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **argv)
{
	char *cmd = NULL, *a_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		a_cmd = _get_cpath(cmd);
		if (execve(a_cmd, argv, NULL) == -1)
			perror("Error: execve failed");
	}
}
