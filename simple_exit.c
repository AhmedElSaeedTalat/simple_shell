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
			if (status[i] < 48  || status[i] > 57)
			{
				_print("-shell: exit:"), _print(status);
				_print(": numeric argument required");
				_print("\n");
				free(buff), free(buff1);
				exit(EXIT_FAILURE);
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
