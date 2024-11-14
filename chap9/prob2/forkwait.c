#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int pid, child, status;
	printf("[%d] Parent Process Start \n", getpid());
	pid = fork();
	if(pid == 0)
	{
		printf("[%d] Child Process Start \n", getpid());
		exit(1);
	}
	child = wait(&status);
	printf("[%d] Child Process %d end", child);
	printf("\t end code %d\n", status>>8);
}
