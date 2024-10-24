#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 24

struct db 
{
	int id;
	char name[MAX];
	char category[MAX];
	int expire;
	int stock;
};

int main(int argc, char  *argv[])
{
	int fd;
	int c;
	struct db record;
	if(argc < 2)
	{
		fprintf(stderr,"How to use: %s file\n", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}
	do
	{
		printf("--Goods query--\n");
		printf("0: list of all goods, 1: list of available goods ");
		scanf(" %d", &c);
		if(c == 0)
		{
		}
		else if(c == 1)
		{
		}
		else
		{
			printf("error");
		}
	}
	close(fd);
	exit(0);
}
