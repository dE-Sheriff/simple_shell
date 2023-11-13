#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @argv: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **argv)
{
	char *cmd = NULL, *a_cmd = NULL;
	int ret;

	_printf("Before execve\n");
	if (argv)
	{
		cmd = argv[0];
		a_cmd = _get_cpath(cmd);
		if (a_cmd != NULL)
		{
			ret = execve(a_cmd, argv, NULL);
			if (ret == -1)
				perror("Error");
		}
	}
		else
			_printf("not accessing argv\n");
}
