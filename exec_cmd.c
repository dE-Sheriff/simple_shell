#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @argv: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **argv)
{
	char *cmd = NULL, *a_cmd = NULL, *envv[] = {NULL};
	int ret;

	printf("Before execve\n");
	if (argv)
	{
		cmd = argv[0];
		a_cmd = _get_cpath(cmd);
		ret = execve(a_cmd, (char **)argv, envv);
		if (ret == -1)
			perror("Error");
	}
	else
		printf("not accessing argv\n");
}
