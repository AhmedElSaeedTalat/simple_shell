#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
extern char **environ;
int _putchar(int c);
void _print(char *str);
char *_getenv(char *name);
int _getlen(char *str);
char *get_path(char *passed_command);
char *_cpy(char *str, char *str2);
int _getline(char **buff);
char *_strtok(char *str, char *passed_delim);
int _cmp(char *str, char *str2);
void print_env(void);
void simple_exit(char *status, char *buff, char *buff1);
char *_setenv(char *name, char *value);
int check_non_command(char *buff, char *token, char *buff1, char **str);
void check_multiple_command(char *str);
void handle(int sig);
int check_full(char *str);
void custom_error(char *str);
#endif
