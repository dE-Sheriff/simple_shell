#include "shell.h"

/**
 * free_dylloc - a function that frees dynamically
 * allocated memory
 * @pptr: the 1st string
 * @num_tem: the 2nd string
 * Return: int
 */

void free_dylloc(char **pptr, int num_tem)
{
	int x;

	for (x = 0; x < num_tem - 1; x++)
	{
		free(pptr[x]);
	}
	free(pptr);
}
