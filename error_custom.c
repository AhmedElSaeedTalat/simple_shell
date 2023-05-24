#include "shell.h"
/**
  * check_full - function to check if a full path
  * is provided
  *
  * @str: string to check
  *
  * Return: Always 1 in case of full path
  * and 0 in case not
  */
int check_full(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '/' && str[i] != ' ')
			return (0);
		else if (str[i] != ' ' && str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
/**
  * custom_error - function to print custom error
  * in case command not found
  *
  * @str: str name to include in the error message
  */
void custom_error(char *str)
{
	write(STDERR_FILENO, str, _getlen(str));
	write(STDERR_FILENO, ": command not found\n", 20);
}
