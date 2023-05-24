#include "shell.h"
/**
  * _cpy - copy string to another
  *
  * @str: fistr string to copy to
  *
  * @str2: second string to copy from
  *
  * Return: copied string
  */
char *_cpy(char *str, char *str2)
{
	int i = 0;

	if (str2 == NULL)
		return (NULL);
	while (str2[i])
	{
		str[i] = str2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
