#include "shell.h"

/**
 * get_argc - counts num of argument
 * @token: stores arguments
 * @inputptr: points to input
 * @delim: delimeter
 * Return: Void
*/

int get_argc(char *token, char *inputptr, const char *delim)
{
	int num_tok = 0;

	if (inputptr == NULL)
		return (0);

	token = strtok(inputptr, delim);
		while (token != NULL)
		{
			num_tok++;
			token = strtok(NULL, delim);
		}
		free(inputptr);
		inputptr = NULL;
		return (num_tok);
}

/**
 * arr_argv - arranges token in array
 * @argv: the allocated space
 * @token: stores arguments
 * @copy_inputptr: copy of direct input
 * Return: pointer to argv
*/

char **arr_argv(char **argv, char *token, char *copy_inputptr)
{
	int xtra, i;
	const char *delim = " \n";

	token = strtok(copy_inputptr, delim);
	for (i = 0; token != NULL; i++)
	{
		xtra = 1;
		argv[i] = allchrptr((int)_strlen(token), xtra);
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(copy_inputptr);
	return (argv);
}
