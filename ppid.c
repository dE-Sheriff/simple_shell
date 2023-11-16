#include "shell.h"

/**
 * _getppid - PID
 *
 * Return: Always 0.
 */

int _getppid(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
