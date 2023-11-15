#include "shell.h"

/**
 * print_promt - displays the prompt
 * Return: Void
*/

void print_promt(void)
{
	if (isatty(STDIN_FILENO) == 1)
		_printf("ks_shell$ ");
}
