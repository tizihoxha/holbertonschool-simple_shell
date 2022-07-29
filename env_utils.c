#include "shell.h"

/**
* str_n_cmp - Function that compares n elements of a string
* @s1: first string
* @s2: second string
* @n: long int to measure the number of elements in a string
* Return: return 1 if s1 > s2, -1 if s1 < s2, or 0
*/
/*
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
*/
/**
* getenv - function that gets environmental variables
* @name - ponter to function
* Return: No return
*/
/**
char* _getenv(const char *name)
{
	int i, j;
	char *str;

	if (name == NULL)
		return (NULL);
	
	for (i = 0; environ[i] ; i++)
	{
		if (name[j] == environ[i][j])
		{
			for (j = 0; name[j]; j++)
			{
				if (name[j] != environ[i][j])
					break;
			}
			if (name[j] == '\0')
			{
				str = (environ[i] + j + 1);
				return (str);
			}
		}
	}
	return (0);
}
*/
/**
* printenv - function that prints environmental variables
* @argc: argument count
* @argv: pointer to argv array
* @environ: pointer to env variable
* Return:  0
*/

int main(int argc, char *argv[], char *environ[])

{
    int i;
    
    for (i = 0; environ[i] != NULL; i++)
	    _puts(environ[i]);
    return (0);
}
