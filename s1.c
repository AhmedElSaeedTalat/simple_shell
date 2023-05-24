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

	_print("#cisfun$ ");
	input = _getline(&buff);
	if (input == 0)
	{
		free(buff);
		_putchar('\n');
		exit(1);
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
	*path = _getenv("PATH"),
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

char *check_accessible(char **av, char **str)
{
	char *buff, *buff1, *token, *full = NULL, *delim = " ;\n";
	int check = 0, check2 = 0;

	buff = get_line();
	buff1 = malloc(sizeof(char) * (_getlen(buff) + 1));
	if (buff1 == NULL)
	{
		free(buff), free(buff1);
		return (NULL);
	}
	_cpy(buff1, buff);
	token = _strtok(buff, delim);
	check2 = check_non_command(buff, token, buff1, str);
	if (check2 == -1)
		return (NULL);
	check = _cmp(token, "env");
	if (check == 1)
	{
		free(buff), free(buff1);
		print_env();
		return (NULL);
	}
	if (access(token, X_OK) != 0)
	{
		full = get_path(token);
		if (access(token, X_OK) != 0 &&  full == NULL)
		{
			perror(av[0]);
			free(buff), free(buff1), free(full);
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
	char *buff = NULL, *full = NULL, *path = NULL, *str = NULL;
	(void) argc;

	while (1)
	{
		buff = check_accessible(argv, &str);
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
			perror(argv[0]);
			exit(EXIT_FAILURE);
		} else
		{
			wait(&status);
			free(full), free(path), free(buff);
			free(str);
		}
	}
	free(full), free(path), free(buff);
	return (0);
}
