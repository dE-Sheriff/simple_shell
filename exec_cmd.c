#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @argv: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **argv)
{
	char *cmd;

	printf("Before execve\n");
	if (argv)
	{
		cmd = argv[0];
		if (execve(cmd, argv, NULL) == -1)
			perror("Error:");
	}
}
