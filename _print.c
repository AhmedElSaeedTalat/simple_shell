#include "shell.h"
/**
  * _print - print string
  *
  * @str: string received to print
  */
void _print(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
