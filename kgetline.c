#include "shell.h"

/**
 * _getline - receives iput from stdin and stires the pointer
 * @line: where iput is stored
 * @n: number
 * @stream: from where
 * Return: ssize_t
*/

ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	char *temp;
	size_t i = 0;
	int ch;

	if (!line || !n || !stream)
		return (-1);
	if (*line == NULL || *n == 0)
	{
		*n = 128;
		*line = (char *)malloc(*n);
		if (*line == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
	}
	while ((ch = fgetc(stream)) != EOF && ch != '\n')
	{
		if (i == *n - 1)
		{
			*n = 2;
			temp = (char *)realloc(*line, *n);
			if (temp == NULL)
			{
				perror("Memory allocation error");
				free(*line);
				*line = NULL;
				return (-1);
			}
				*line = temp;
		}

		(*line)[i++] = (char)ch;
	}
	if (ch == EOF && i == 0)
		return (-1);
	(*line)[i] = '\0';
	return (i);
}
