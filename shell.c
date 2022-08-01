#include "shell.h"

/**
 * 
 *
 *
 */
char *name;
/**
 * @name: global variable
 */

int main(int __attribute__ ((unused))argc, char *argv[])
{
	char *line = NULL;
	size_t buffer = 0;
	ssize_t chars = 0;
	
	name = argv[0];
	while(1)
	{
		if (isatty(0) == 1) /* 0 = STDIN_FILENO */
			write(1, "$ ", 2);
		chars = getline(&line, &buffer, 0);
		if (char == -1)
		{
			if (isatty(0) == 1)
				write(1 , "\n", 1);
			break;
		}
		if (line[chars - 1] == '\n')
			line[chars - 1] = '\0';
		if (*line)
			continue;
		if (command_read(line, chars) == 2)
			break;
	}
	free(line);
	line = NULL;
	return (0);
}
