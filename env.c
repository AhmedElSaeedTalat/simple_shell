#include "shell.h"
/**
  * print_env - print environment variables
  */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_print(environ[i]);
		_print("\n");
	}
}
