#include "shell.h"

/**
*
*
*
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
*
*
*
*/

void _printenv(char **environ)
{
	int i;
	
	for (i = 0; environ[i] ; i++)
		_putchar(environ[i]);
}

/**
*
*
*
*/

char *_getenv(int argc, char *argv[], char *envp[])
{
    int i;
    
    for (i = 0; envp[i] != NULL; i++)
	    printf("\n%s", envp[i]);
    getchar();
    return (0);
}
