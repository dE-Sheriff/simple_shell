#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int _strcmp(char *s1, char *s2);
void _execmd(char **sptr);
void free_dylloc(char **pptr, int num_tem);
char *_strcpy(char *src, char *dest);
void print_promt(void);
int _printf(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);
void _chckarg(const char *format, int char_len, va_list arg_list);
int print_int(va_list a_list);
char *_getenv(const char *name);
char *_get_cpath(char *cmd);

#endif /* SHELL_H */
