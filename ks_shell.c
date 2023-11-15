#include "shell.h"

/**
 * dal_chrptr - allocates memory to char pointer
 * @size: size to allocate
 * @extra: extra allocation
 * Return: pointer to char pointer
*/
char **dal_chrptr(int size, int extra)
{
	char **allocated;

	allocated = malloc(sizeof(char *) * size + extra);
	if (!allocated)
	{
		perror("Error: Memory allocation error");
		exit(EXIT_FAILURE);
	}
	return (allocated);
}

/**
 * allchrptr - allocates memory to char pointer
 * @size: size to allocate
 * @extra: extra allocation
 * Return: char pointer
*/
char *allchrptr(int size, int extra)
{
	char *allocated;

	allocated = malloc(sizeof(char) * (size + extra));
	if (!allocated)
	{
		perror("Error: Memory allocation error");
		exit(EXIT_FAILURE);
	}
	return (allocated);
}

/**
 * main -  a UNIX command line interpreter
 * @argc: count of string received
 * @argv: string received
 * Return: int
*/

int main(int argc, char **argv)
{
	char *inputptr = NULL, *copy_inputptr, *token = NULL;
	const char *delim = " \n";
	char **new_argv;
	int num_tok = 0, xtra;
	bool receive_cmd = true, other_cmd = false;
	size_t x = 0;
	ssize_t num_charrd;
	(void)argc;

	while (receive_cmd && !other_cmd)
	{
		if (isatty(STDIN_FILENO) == 0)
			other_cmd = true;
		print_promt();
		num_charrd = getline(&inputptr, &x, stdin);
		if (num_charrd == -1)
		{
			_printf("Exiting shell...\n");
			exit(EXIT_FAILURE);
		}
		if (inputptr[num_charrd - 1] == '\n')
			inputptr[num_charrd - 1] = '\0';

		xtra = 0;
		copy_inputptr = allchrptr((int) num_charrd, xtra);
		_strcpy(copy_inputptr, inputptr);

		num_tok = get_argc(token, inputptr, delim);
		xtra = 0;
		argv = dal_chrptr((int)num_tok, xtra);
		new_argv = arr_argv((char **)argv, token, (char *)copy_inputptr);
		if (((char *)argv[0] != NULL) && _strcmp((char *)argv[0], "exit") == 0)
		{
			free_dylloc(new_argv, num_tok);
			exit(0);
		}
		_execmd(new_argv);
		free_dylloc(new_argv, num_tok);
	}
	return (0);
}
