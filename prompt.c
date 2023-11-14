#include "shell.h"

/**
 * print_promt - displays the prompt
 * Return: Void
*/

void print_promt(void)
{
	_printf("ks_shell$ ");
}

/**
 * get_promt - displays the prompt accepts input
 * @inputptr: stores input
 * @x: - another
 * Return: number of characters in input
*/

/**
* ssize_t get_promt(char *inputptr, size_t x)
* {
* 	ssize_t num_charrd;
* 
* 	_printf("ks_shell$ ");
* 	num_charrd = getline(&inputptr, &x, stdin);
* 	if (num_charrd == -1)
* 	{
* 		_printf("Exiting shell...\n");
* 		exit(EXIT_FAILURE);
* 	}
* 	if (inputptr[num_charrd - 1] == '\n')
* 		inputptr[num_charrd - 1] = '\0';
* 	return (num_charrd);
* }
*/
