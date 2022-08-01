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
