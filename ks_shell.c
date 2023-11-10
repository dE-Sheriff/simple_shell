#include "shell.h"

/**
 * main -  a UNIX command line interpreter
 * Return: int
*/

int main(void)
{
	char *inputptr, *copy_inputptr, *token;
	char **argv;
	const char *delim = " ";
	int num_tok = 0, i;
	bool receive_cmd = true;
	size_t x = 0;
	ssize_t num_charrd;

	while (receive_cmd)
	{
		print_promt();
		num_charrd = getline(&inputptr, &x, stdin);
		if (num_charrd == -1)
		{
			_printf("Closing shell...\n");
			exit(EXIT_FAILURE);
		}

		/* copy input before using strtok*/
		copy_inputptr = malloc(sizeof(char) * num_charrd);
		if (!copy_inputptr)
			return (-1);
		_strcpy(copy_inputptr, inputptr);

		/* use strtok function*/
		/* make this a function of its own*/
		token = strtok(inputptr, delim);
		while (token != NULL)
		{
			num_tok++;
			token = strtok(NULL, delim);
		}
		num_tok++;

		/* alocate a memory that point to token pointers*/
		/* make a stand alone funtion*/
		argv = malloc(sizeof(char *) * num_tok);
		token = strtok(copy_inputptr, delim);
		if (argv != NULL)
		{
			for (i = 0; token != NULL; i++)
			{
				argv[i] = malloc(sizeof(char) * _strlen(token)+1);
				if (argv[i] == NULL)
					exit(EXIT_FAILURE);
			}
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		_execmd(argv);

		/* Free allocated memories*/
		free_dylloc(argv, num_tok);
		free(copy_inputptr);
	}
	return (0);
}
