#include "shell.h"
/**
  * check_non_command - check if command is not executable
  *
  * @buff: to tokenize and free
  *
  * @buff1: to tokenize and free
  * @str: to store str and to free
  * @token: token to check
  *
  * Return: -1 to return NULL and skip rest of the code
  * or 1 in case not command line was passed
  */
int check_non_command(char *buff, char *token, char *buff1, char **str)
{
	char *status, *token1, *token2, *delim = " \n";
	int check = 0, counter = 0;

	check = _cmp(token, "exit");
	if (check == 1)
	{
		free(*str);
		status = _strtok(NULL, delim);
		simple_exit(status, buff, buff1);
	}

	check = _cmp(token, "setenv");
	if (check == 1)
	{
		while (token != NULL)
		{
			counter++;
			token = _strtok(NULL, delim);
		}
		if (counter > 3)
		{
			write(STDERR_FILENO, "not correct number of arguments\n", 32);
			free(buff), free(buff1);
			return (-1);
		}
		token = _strtok(buff1, delim);
		token1 = _strtok(NULL, delim);
		token2 = _strtok(NULL, delim);
		*str = _setenv(token1, token2);
		free(buff), free(buff1);
		return (-1);
	}
	return (1);
}
