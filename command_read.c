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

	if (_strcmp(str, "exit") == 0)
		return (2);
	if (_strcmp(str, "env") == 0)
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
