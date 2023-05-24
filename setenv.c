#include "shell.h"
/**
  * _strconc1 - concatinate name and value
  *
  * @name: environment variable name
  *
  * @value: environment variable value
  * @str: newly created string
  */
void _strconc1(char **str, char *name, char *value)
{
	int i, y;

	i = 0;
	while (name[i])
	{
		(*str)[i] = name[i];
		i++;
	}
	(*str)[i] = '=';
	i++;
	y = 0;
	while (value[y])
	{
		(*str)[i] = value[y];
		i++, y++;
	}
	(*str)[i] = '\0';
}
/**
  * find_index - sets environment variable
  *
  * @name: environment variable name
  *
  * @name_len: name length
  *
  * Return: index of variable found
  */

int find_index(int name_len, char *name)
{
	int i, y, check;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (y = 0; y < name_len; y++)
		{
			if (name[y] != environ[i][y])
			{
				check = 0;
				break;
			}
			check = 1;
		}
		if (check == 1)
			return (i);
	}
	return (-1);
}
/**
  * _setenv - sets environment variable
  *
  * @name: environment variable name
  *
  * @value: environment variable value
  * Return: char to the new string
  */
char *_setenv(char *name, char *value)
{
	int len, name_len, value_len, y, count, counter, index;
	char *n = _getenv(name), *new_str = NULL;

	name_len = _getlen(name);
	value_len = _getlen(value);
	if (n == NULL)
	{
		len = 0;
		while (environ[len] != NULL)
			len++;
		new_str = malloc(sizeof(char) * (name_len + value_len + 2));
		_strconc1(&new_str, name, value);
		environ[len] = new_str;
		environ[len + 1] = NULL;
		free(n);
	} else
	{
		if (n == value)
		{
			free(n);
			return (NULL);
		}
		else if (n != value)
		{
			index = find_index(name_len, name);
			count = counter = 0;
			for (y = 0; environ[index][y] != '\0'; y++)
			{
				if (environ[index][y] == '=')
				{
					count = 1;
					continue;
				}
				if (count == 1)
					environ[index][y] = value[counter++];
			}
		}
		free(n);
	}
	return (new_str);
}
