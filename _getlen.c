#include "shell.h"
/**
  * _getlen - get len of string
  *
  * @str: string received to check
  * Return: string length
  */
int _getlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}
