#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

char *allchrptr(int size, int extra);
int get_argc(char *token, char *inputptr, const char *delim);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void _execmd(char **sptr);
void free_dylloc(char **pptr, int num_tem);
char *_strcpy(char *src, char *dest);
void print_promt(void);
ssize_t get_promt(char *inputptr, size_t x);
int _printf(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);
void _chckarg(const char *format, int char_len, va_list arg_list);
char **arr_argv(char **argv, char *token, char *copy_inputptr);
int print_int(va_list a_list);
char *_getenv(const char *name);
char *_get_cpath(char *cmd);

#endif /* SHELL_H */
