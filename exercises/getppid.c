#include <unistd.h>
#include <stdio.h>

/**
 * main - function that prints pid and ppid
 *
 * Return: 0
 */

int main(void)
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("pid nr: %i\n", pid);
	printf("ppid nr: %i\n", ppid);

	return (0);
}
