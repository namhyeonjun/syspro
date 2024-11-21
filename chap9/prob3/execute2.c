#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Parental Process Start\n");
	if(fork() == 0)
	{
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "First Failure");
		exit(1);
	}
	if(fork() == 0)
	{
		execl("/bin/date", "date", NULL);
		fprintf(stderr, "Second Failure");
		exit(2);
	}
	if (fork() == 0)
	{
		execl("/bin/ls", "ls", "-l", NULL);
		fprintf(stderr, "Third  Failure");
		exit(3);
	}
	printf("Parental Process End\n");
}
