#include "shell.h"

/**
 * _execmd - executes command inteden by user
 * @argv: array of tokenized arguments
 * Return: Void
*/

void _execmd(char **argv)
{
	char *cmd = NULL, *a_cmd = NULL;
	char *envv[] = {NULL};
	int ret;
	pid_t baby_pid;

	printf("Before execve\n");
	if (argv)
	{
		cmd = (char *)argv[0];
		a_cmd = _get_cpath(cmd);
		_printf("%s\n", a_cmd);

		baby_pid = fork();
		if (baby_pid == -1)
		{
			perror("Child forking Error");
			exit(EXIT_FAILURE);
		}
		else if (baby_pid == 0)
		{
			ret = execve(a_cmd, (char **)argv, envv);
			if (ret == -1)
				perror("Error");
		}
		else
		{
			wait(NULL);
		}
	}
}
