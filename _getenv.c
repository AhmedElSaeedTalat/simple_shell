#include "shell.h"
/**
  * _cmp - compare 2 strings
  *
  * @str: first string to compare
  *
  * @str2: second string to compare
  * Return: 1 in case they are identical
  * negative 1 in case the are not
  */
int _cmp(char *str, char *str2)
{
	int i = 0;

	while (str2[i])
	{
		if (str[i] != str2[i])
			return (-1);
		i++;
	}
	return (1);
}
/**
  * error - handle error
  *
  * @str: to free memory in case of error
  */
void error(char *str)
{
	free(str);
	exit(-1);
}
/**
  * _getenv - get env variable value
  *
  * @name: path variable to look for it's value
  *
  * Return: value of the env value
  */
char *_getenv(char *name)
{
	int i, y, len, cmp_val, new_len, count;
	char *str, *new_str;

	len = new_len = count = 0;
	while (name[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		error(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (y = 0; y < len; y++)
		{
			str[y] = environ[i][y];
		}
		str[y] = '\0';
		cmp_val = _cmp(str, name);
		if (cmp_val > -1)
		{
			free(str);
			for (y = len + 1; environ[i][y] != '\0'; y++)
				new_len++;
			new_str = malloc(sizeof(char) * (new_len + 1));
			if (new_str == NULL)
				error(new_str);
			for (y = len + 1; environ[i][y] != '\0'; y++)
			{
				new_str[count] = environ[i][y];
				count++;
			}
			new_str[count] = '\0';
			return (new_str);
		}
	}
	return (NULL);
}
