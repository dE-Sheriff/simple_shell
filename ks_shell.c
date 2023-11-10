#include "shell.h"

/**
 * main -  a UNIX command line interpreter
 * Return: int
*/

int main(void)
{
	char *inputptr, *copy_inputptr, *token;
	char **argv;
	const char *delim = " \0";
	int num_tok = 0, i, counter;
	bool receive_cmd = true;
	size_t x = 0;
	ssize_t num_charrd;
	
	while (receive_cmd)
	{
		print_promt();
		num_charrd = getline(&inputptr, &x, stdin);
		if (num_charrd == -1)
		{
			printf("Exiting shell...\n");
			exit(EXIT_FAILURE);
		}

		/* Test if input was received, stored and pointed to*/
		_printf("%s\n", inputptr);

		/* copy input before using strtok*/
		copy_inputptr = malloc(sizeof(char) * num_charrd);
		if (!copy_inputptr)
			return (-1);
		_strcpy(inputptr, copy_inputptr);

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
		for (i =0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		
		/* Test code thus far by printing each stored token*/
		for (counter = 0; counter < num_tok - 1; counter++)
		{
			_printf("%s\n", argv[counter]);
		}

		free(argv);
		free(inputptr);
		free(copy_inputptr);
	}
	return (0);
}
