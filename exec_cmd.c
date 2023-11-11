#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @argv: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **argv)
{
	char *cmd = NULL, *envv[] = {"NULL"}, *a_cmd = NULL;
	int ret;

	printf("Before execve\n");
	if (argv)
	{
		cmd = argv[0];
		a_cmd = _get_cpath(cmd);
		ret = execve(cmd, argv, envv);
		if (ret == -1)
			perror("Error");
	}
}
