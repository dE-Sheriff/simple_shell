#include "main.h"

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 * Return: void
 */

void rev_string(char *s)
{
	char r = s[0];
	int coun = 0;
	int a;

	while (s[coun] != '\0')
		coun++;
	for (a = 0; a < coun; a++)
	{
		coun--;
		r = s[a];
		s[a] = s[coun];
		s[coun] = r;
	}
}

/**
 * _pfitoa - reverses a string
 * @str: the string to reverse
 * @num: the num to change to string
 * Return: the string
 */

char *_pfitoa(int num, char *str)
{
	int i = 0;
	bool isNeg = false;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (num < 0)
	{
		isNeg = true;
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % 10;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / 10;
	}

	if (isNeg)
		str[i++] = '-';
	str[i] = '\0';
	rev_string(str);
	return (str);
}

/**
 * len_int - measure digits in integer
 * @o_x: the integer
 * Return: char_len
 */

int len_int(int o_x)
{
	int len = 0;

	if (o_x < 0)
		len++;
	if (o_x == 0)
		len++;
	else
		while (o_x != 0)
		{
			o_x = o_x / 10;
			len++;
		}
	return (len);
}

/**
 * print_int - print prints string when format == 'i' or 'd'
 * @a_list: vaariadiac list
 * Return: char_len
 */

int print_int(va_list a_list)
{
	int o_int;
	int len;
	char *str_pr;
	char *str;

	o_int = va_arg(a_list, int);
	len = len_int(o_int);
	str = (char *)malloc(len * sizeof(char));

	str_pr = _pfitoa(o_int, str);

	write(1, str_pr, len);
	free(str);
	return (len);
}
