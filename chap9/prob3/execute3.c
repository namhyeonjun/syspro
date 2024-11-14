#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int child, pid, status;
	pid = fork();
	if (pid == 0)
	{
		execvp(argv[1], &argv[1]);
		fprintf(stderr, "%s:Unable to execute\n", argv[1]);
	}
	else
	{
		child = wait(&status);
		printf("[%d] Child Process %d End\n", getpid(), pid);
		printf("end code %d\n", status>>8);
	}
}
