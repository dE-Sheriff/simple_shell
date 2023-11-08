#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *_strcpy(char *src, char *dest);
void print_promt(void);
int _printf(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);
void _chckarg(const char *format, int char_len, va_list arg_list);
int print_int(va_list a_list);

#endif /* SHELL_H */
