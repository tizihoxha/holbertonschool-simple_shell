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
		if (chars == -1)
		{
			if (isatty(0) == 1)
				write(1, "\n", 1);
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

int execute(char *cmd_arr[])
{
	char *execute_path = NULL;
	char *cmd = NULL;
	pid_t pid;
	int status;

	cmd = cmd_arr[0];
	execute_path = command_path(cmd);
	if (execute_path == NULL)
	{
	        write(2, name, _strlen(name));
		write (2, ": ", 2);
	        write(2, cmd, _strlen(cmd));
		write(2, ": not found\n", 12);

		return (3);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (pid > 0)
		wait(&status);
	else if (pid == 0)
	{
	  if (environ)
	    {
		(execve(execute_path, cmd_arr, environ));
		perror("Error:");
		exit(1);
	    }
	  else
	    {
	      execve(execute_path, cmd_arr, NULL);
	    }
	}
	free(execute_path);
	return (0);
}
