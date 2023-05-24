#include "shell.h"
/**
  * check_delim - checks number of delimiters
  *
  * @ptr: pointer received to check
  *
  * @delim: delimeter string received
  * Return: number of delimiters
  */
int check_delim(char *ptr, char *delim)
{
	int i, y, signal, counter = 0;

	for (i = 0; ptr[i] != '\0'; i++)
	{
		signal = 0;
		for (y = 0; delim[y] != '\0'; y++)
		{
			if (ptr[i] == delim[y])
			{
				counter++;
				signal = 1;
				continue;
			}
		}
		if (signal == 0)
			return (counter);
	}
	return (counter);
}
/**
  * helper_function - loop over string
  *
  * @ptr: pointer received to check
  *
  * @passed_delim: delimeter string received
  *
  * @ptr2: received pointer to store
  * @str: reived string
  *
  * Return: pointer to token
  */
char *helper_function(char *str, char **ptr2, char *ptr, char *passed_delim)
{
	int i, y, z, counter = 0, delim = 0;

	if (*str == '\0' && _getlen(str) == 0)
		return (NULL);
	for (i = 0; *str != '\0'; i++)
	{
		for (y = 0; passed_delim[y] != '\0'; y++)
		{
			if (*str == passed_delim[y])
			{
				delim = 1, counter = check_delim(str, passed_delim);
				for (z = 0; z < counter; z++)
					*str = '\0', str++;
				*ptr2 = str;
				if (*ptr == '\0')
				{
					ptr = *ptr2;
					continue;
				}
				return (ptr);
			}
		}
		str++;
	}
	if (delim == 0)
	{
		*str = '\0', *ptr2 = NULL;
		return (ptr);
	}
	return (ptr);
}
/**
  * _strtok - Entry point
  *
  * @str: string received to tokenize
  *
  * @passed_delim: passed delimiter
  * Return: token
  */
char *_strtok(char *str, char *passed_delim)
{
	static char *ptr2, *ptr3, *ptr4, *ptr_delim;
	char *ptr;

	if (str == NULL && ptr2 == NULL)
		return (NULL);
	else if (str != NULL && str == ptr4 && ptr_delim == passed_delim)
		return (str);
	else if (str != NULL && ptr_delim != passed_delim)
		ptr = str, ptr3 = ptr4 = str, ptr_delim = passed_delim;
	else if ((str != NULL && ptr2 == NULL) || (str != NULL && str != ptr3))
		ptr = str, ptr3 = ptr4 = str, ptr_delim = passed_delim;
	else if (str == NULL && ptr2 != NULL)
		str = ptr = ptr2;
	else
		return (NULL);

	ptr = helper_function(str, &ptr2, ptr, passed_delim);
	return (ptr);
}
