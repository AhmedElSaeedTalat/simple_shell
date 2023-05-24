#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 *
 * @c: print character
 *
 * Return: On success 1
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
