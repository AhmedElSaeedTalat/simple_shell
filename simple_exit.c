#include "shell.h"
/**
  * simple_exit - exit file when exit passed
  *
  * @status: status code to print
  * @buff: buff to free
  * @buff1: buff1 to free on exit
  */
void simple_exit(char *status, char *buff, char *buff1)
{
	int i, code, converted;

	i = code = converted = 0;
	if (status != NULL)
	{
		while (status[i])
		{
			if (status[0] == '-')
			{
				write(STDERR_FILENO, "./hsh: 1: exit: Illegal number:", 31);
				write(STDERR_FILENO, status, _getlen(status));
				write(STDERR_FILENO, "\n", 1);
				free(buff), free(buff1), exit(2);
			} else if (status[i] < 48  || status[i] > 57)
			{
				write(STDERR_FILENO, "./hsh: 1: exit: Illegal number:", 31);
				write(STDERR_FILENO, status, _getlen(status));
				write(STDERR_FILENO, "\n", 1);
				free(buff), free(buff1);
				exit(2);
			}
			i++;
		}
		i = 0;
		while (status[i])
		{
			converted = status[i] - '0';
			code *= 10;
			code += converted;
			i++;
		}
		free(buff), free(buff1);
		if (code > 255)
			exit(code % 256);
		exit(code);
	} else
	{
		free(buff), free(buff1);
		exit(EXIT_SUCCESS);
	}
}
