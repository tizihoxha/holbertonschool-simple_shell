#include "shell.h"

/**
* str_n_cmp - Function that compares n elements of a string
* @s1: first string
* @s2: second string
* @n: long int to measure the number of elements in a string
* Return: return 1 if s1 > s2, -1 if s1 < s2, or 0
*/

int _str_n_cmp(const char *s1, const char *s2, size_t n)
{
	char c1;
	char c2;
	
	while (n)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)
		{
			if (c1 > c2)
				return (1);
			else
			{
				if (c1 < c2)
					return (-1);
				else
					return (0);
			}
		}
		n--;
	}
}

/**
* printenv - function that prints environmental variables
* @environ - ponter to function
* Return: No return
*/

void _printenv(char **environ)
{
	int i;
	
	for (i = 0; environ[i] ; i++)
		_putchar(environ[i]);
}

/**
* getenv - function that gets environmental variables
* @argc: argument count
* @argv: pointer to argv array
* @envp: pointer to envp array
* Return:  0
*/

int _getenv(int argc, char *argv[], char *envp[])
{
    int i;
    
    for (i = 0; envp[i] != NULL; i++)
	    printf("\n%s", envp[i]);
    getchar();
    return (0);
}
