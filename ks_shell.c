#include "shell.h"

/**
 * main -  a UNIX command line interpreter
 * Return: int
*/

int main(int argc, char **argv)
{
	char *inputptr = NULL, *copy_inputptr, *token = NULL;
	const char *delim = " \n";
	int num_tok = 0, i;
	bool receive_cmd = true;
	bool other_cmd = false;
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

		/*create a child pid*/
		baby_pid = fork();
		if (baby_pid == -1)
		{
			perror("child  forking failed");
			exit(EXIT_FAILURE);
		}
		if (baby_pid == 0)


		/* copy input before using strtok*/
		copy_inputptr = malloc(sizeof(char) * num_charrd + 1);
		if (!copy_inputptr)
		{
			return (-1);
		}
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
		if (!argv)
		{
			perror("Error: argv Merory allocation error");
			exit(EXIT_FAILURE);
		}
		token = strtok(copy_inputptr, delim);
		for (i =0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			if (!argv[i])
			{
				perror("Error: argv[i]Memory allocation error");
				exit(EXIT_FAILURE);
			}
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		_execmd(argv);
	}

	free_dylloc(argv, num_tok);
	free(copy_inputptr);

	return (0);
}
