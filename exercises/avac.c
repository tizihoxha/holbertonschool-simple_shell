#include <stdio.h>
#include <stdlib.h>

/**
 * main - a function that prints all arguments
 * @ac: av num
 * @av: string array
 * Return: 0
 */

int main(int ac, char **av)
{
	int len;

	for (len = 0; av[len]; len++)
	{
		printf("%s", av[len]);
	}
	printf("\n");
	return (0);
}
