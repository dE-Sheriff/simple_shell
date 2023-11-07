#include "shell.h"

/**
 * _chckarg - checks the specifiers and do as neccessary
 * @format: the specifier
 * @char_len: character printed
 * @arg_list: the variadiac fun
 * Return: void
 */

void _chckarg(const char *format, int char_len, va_list arg_list)
{
	int ch, s_len;
	char *str;

	if (*format == '%')
	{
		write(1, format, 1);
		char_len++;
	}
	else if (*format == 'c')
	{
		ch = va_arg(arg_list, int);
		write(1, &ch, 1);
		char_len++;
	}
	else if (*format == 's')
	{
		str = va_arg(arg_list, char *);
		s_len = _strlen(str);
		write(1, str, s_len);
		char_len += s_len;
	}
}
