#include "shell.h"
/**
*
*
*
*/
int my_strncmp(const char *s1, const char *s2, size_t n)
int _str_n_cmp(char *s1, char *s2, int n)
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

char *_getenv(const char *name)
{
    int i, j;
    int status;

for (i = 0; environ[i] != NULL; i++)
{
    status = 1;
    for (j = 0; environ[i][j] != '='; j++)
    {
        if (name[j] != environ[i][j])
        {
            status = 0;
            break;
        }
    }

    if (status)
    {
        return (&environ[i][j + 1]);
    }
}
return (NULL);
}