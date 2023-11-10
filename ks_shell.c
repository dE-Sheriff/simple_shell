#include "shell.h"

/**
 * main -  a UNIX command line interpreter
 * Return: int
*/

int main(void)
{
	char *inputptr = NULL, *copy_inputptr, *token = NULL;
	char **argv = NULL;
	const char *delim = " \0";
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
			printf("Exiting shell...\n");
			exit(EXIT_FAILURE);
		}

		/* copy input before using strtok*/
		copy_inputptr = malloc(sizeof(char) * num_charrd + 1);
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
		for (i =0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		_execmd(argv);

		free(copy_inputptr);
		free_dylloc(argv, num_tok);
	}
	return (0);
}
