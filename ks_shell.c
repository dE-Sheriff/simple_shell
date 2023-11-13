#include "shell.h"

/**
 * main -  a UNIX command line interpreter
 * Return: int
*/

int main(int ac, char **argv)
{
	char *inputptr = NULL, *copy_inputptr, *token = NULL;
	const char *delim = " ";
	int num_tok = 0, i;
	bool receive_cmd = true;
	size_t x = 0;
	ssize_t num_charrd;

	(void)ac;
	
	while (receive_cmd)
	{
		print_promt();
		num_charrd = getline(&inputptr, &x, stdin);
		if (num_charrd == -1)
		{
			_printf("Exiting shell...\n");
			return (-1);
		}

		/* copy input before using strtok*/
		copy_inputptr = malloc(sizeof(char) * num_charrd);
		if (!copy_inputptr)
		{
			perror("memory allocation error");
			return (-1);
		}
		strcpy(copy_inputptr, inputptr);

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
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		_execmd(argv);

		for (i = 0; i < num_tok - 1; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(inputptr);
		free(copy_inputptr);
	}

	return (0);
}
