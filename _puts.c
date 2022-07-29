#include "shell.h"

/**
 * puts - prints string
 * @string: string to be printed
 * Return: no return
 */
void _puts(char* string)
{
	int i = 0;

	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}
	_putchar('\n');
}
