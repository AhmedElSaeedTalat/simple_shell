#include "shell.h"
/**
  * _getline - custom function for getline
  *
  * @buff: buff to store string to
  * Return: number of read bytes
  */
int _getline(char **buff)
{
	static char new_buff[1024];
	int read_file = 0;

	read_file = read(STDIN_FILENO, new_buff, 1024);
	if (read_file == -1)
		return (-1);
	new_buff[read_file] = '\0';
	*buff = malloc(sizeof(char) * (read_file + 1));
	if (*buff == NULL)
	{
		free(*buff);
		return (-1);
	}
	 _cpy(*buff, new_buff);
	return (read_file);
}
