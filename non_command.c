#include "shell.h"
/**
  * check_non_command - check if command is not executable
  *
  * @buff: to tokenize and free
  *
  * @buff1: to tokenize and free
  * @token: token to check
  *
  * Return: -1 to return NULL and skip rest of the code
  * or 1 in case not command line was passed
  */
int check_non_command(char *buff, char *token, char *buff1)
{
	char *status, *delim = " \n";
	int check = 0;

	check = _cmp(token, "exit");
	if (check == 1)
	{
		status = _strtok(NULL, delim);
		simple_exit(status, buff, buff1);
	}

	check = _cmp(token, "env");
	if (check == 1)
	{
		free(buff), free(buff1);
		print_env();
		return (-1);
	}

	check = _cmp(token, "^C");
	if (check == 1)
	{
		free(buff), free(buff1);
		exit(EXIT_SUCCESS);
	}

	return (1);
}
