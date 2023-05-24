#include "shell.h"
/**
  * handle - handle signal for exit
  * @sig: sing variable
  */
void handle(int sig)
{
	(void) sig;
	exit(EXIT_SUCCESS);
}

