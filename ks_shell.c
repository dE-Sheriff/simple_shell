#include "shell.h"

/**
 * main -  a UNIX command line interpreter
 * Return: int
*/

int main(void)
{
	char command[128];
	bool receive_cmd = true;

	while (receive_cmd)
	{
		display_blinker();
	}
}
