#include "shell.h"
/**
  * get_line - add prompt
  * gets tokens
  *
  * Return: read string
  */
char *get_line()
{
	char *buff = NULL;
	ssize_t input;

	if (isatty(0))
		_print("#cisfun$ ");
	input = _getline(&buff);
	if (input == 0)
	{
		free(buff);
		if (isatty(0))
			_putchar('\n');
		exit(EXIT_SUCCESS);
	}
	return (buff);
}

/**
  * execute - execute commands passed
  * to shell
  *
  * @buff: buffer passed to program
  *
  * @path: path argument for path variables
  * @full: full path of command
  */
void execute(char **buff, char **path, char **full)
{
	char *token, *token1, *argv[10], *envp[10];
	int i = 0;
	char *delim = " ;\n";

	token = _strtok(*buff, delim);
	token1 = token;
	while (token != NULL)
	{
		argv[i] = token;
		token = _strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	*path = _getenv("PATH");
	envp[0] = *path;
	envp[1] = NULL;
	if (access(token1, X_OK) != 0)
	{
		*full = get_path(token1);
		if (*full != NULL)
		{
			if (access(*full, X_OK) == 0)
			{
				execve(*full, argv, envp);
				free(*full), free(*path), free(*buff);
				exit(EXIT_FAILURE);
			}
		}
	} else
	{
		execve(token1, argv, envp);
		free(*full), free(*path), free(*buff);
		exit(EXIT_FAILURE);
	}
	free(*buff), free(*path), free(*full);
	exit(EXIT_FAILURE);
}
/**
  * check_accessible - check if command is executable
  *
  * @av: arguments passed to main origram
  * @str: string for setenv to free
  * Return: buffer provided by user
  */

char *check_accessible(char **av)
{
	char *buff, *buff1, *token, *full = NULL, *delim = " ;\n";
	int if_full, check2 = 0;

	buff = get_line();
	if (buff == NULL || (*buff == ' ' && _getlen(buff) == 2) ||
			(*buff == '\n' && _getlen(buff) == 1))
	{
		free(buff);
		return (NULL);
	}
	buff1 = malloc(sizeof(char) * (_getlen(buff) + 1));
	if (buff1 == NULL)
	{
		free(buff), free(buff1);
		return (NULL);
	}
	_cpy(buff1, buff);
	token = _strtok(buff, delim);
	check2 = check_non_command(buff, token, buff1);
	if (check2 == -1)
		return (NULL);
	if_full = check_full(token);
	if (access(token, X_OK) != 0)
	{
		if (if_full == 1)
		{
			perror(av[0]);
			free(buff), free(buff1), free(full);
			return (NULL);
		}
		full = get_path(token);
		if (access(token, X_OK) != 0 &&  full == NULL)
		{
			custom_error(token, av), free(buff), free(buff1), free(full);
			return (NULL);
		}
	}
	free(buff), free(full);
	return (buff1);
}

/**
  * main - Entry point
  *
  * @argc: number of arguments
  *
  * @argv: arguments passed
  *
  * Return: Always 0 (Success)
  */
int main(int argc, char *argv[])
{
	pid_t pid;
	int status;
	char *buff = NULL, *full = NULL, *path = NULL;
	(void) argc;

	signal(SIGINT, handle);
	while (1)
	{
		buff = check_accessible(argv);
		if (buff != NULL)
		{
			pid = fork();
			if (pid == -1)
				exit(EXIT_FAILURE);
		} else
		{
			free(full), free(path), free(buff);
			continue;
		}
		if (pid == 0)
		{
			execute(&buff, &full, &path);
		} else
		{
			wait(&status);
			free(full), free(path), free(buff);
		}
	}
	free(full), free(path), free(buff);
	return (0);
}
