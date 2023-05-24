#include "shell.h"
/**
  * _strconc - concat 2 strings
  *
  * @str: string that will receive both strings
  *
  * @token: first string, part of the path, to check
  * command with
  *
  * @passed_command: passed command like ls
  */
void _strconc(char **str, char *token, char *passed_command)
{
	int i, y;

	i = 0;
	while (token[i] != '\0')
	{
		(*str)[i] = token[i];
		i++;
	}
	(*str)[i] = '/';
	i++;
	y = 0;
	while (passed_command[y])
	{
		(*str)[i] = passed_command[y];
		i++, y++;
	}
	(*str)[i] = '\0';
}
/**
  * get_path - get full path of command
  *
  * @passed_command: passed command
  *
  * Return: full path
  */
char *get_path(char *passed_command)
{
	char *path, *str;
	char *token = NULL, *delim = ":";
	int len, i, num_path;

	len = i = num_path = 0;
	path = _getenv("PATH");
	while (path[i])
	{
		if (path[i] == ':')
			num_path++;
		i++;
	}
	num_path++, i = 0;
	token = _strtok(path, delim);
	len = _getlen(token) + _getlen(passed_command) + 2;
	str = malloc(sizeof(char) * len);
	_strconc(&str, token, passed_command);
	while (access(str, X_OK) != 0 && i < 8)
	{
		token = _strtok(NULL, delim);
		len = _getlen(token) + _getlen(passed_command) + 2;
		free(str);
		str = malloc(sizeof(char) * len);
		_strconc(&str, token, passed_command);
		i++;
	}
	if (access(str, X_OK) == 0)
	{
		free(path);
		return (str);
	}
	free(str), free(path);
	return (NULL);
}
