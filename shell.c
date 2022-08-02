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
		chars = getline(&line, &buffer, stdin);
		if (chars == -1)
		{
			if (isatty(0) == 1)
				write(1, "\n", 1);
			break;
		}
		if (line[chars - 1] == '\n')
			line[chars - 1] = '\0';
		if (*line == '\0')
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
	        write(2, name, strlen(name));
		write (2, ": ", 2);
	        write(2, cmd, strlen(cmd));
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

#include "shell.h"

/**
 * command_read - function that reads commands
 * @str: pointer to string
 * Return: status code
 */

int command_read(char *str, size_t __attribute__((unused))characters)
{
	char *token = NULL;
	char *cmd_arr[100];
	int i;

	if (strcmp(str, "exit") == 0)
		return (2);
	if (strcmp(str, "env") == 0)
		return (_printenv());
	token = strtok(str, " "), i = 0;
	while (token)
	{
		cmd_arr[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_arr[i] = NULL;
	return (execute(cmd_arr));
}
