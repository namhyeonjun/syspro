#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid;
	pritnf("[%d] Process Start \n", getpid());
	pid = fork();
	printf("[%d] Process : return value %d\n", getpid(), pid);
}
