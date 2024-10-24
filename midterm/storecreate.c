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
	struct db record;
	if(argc < 2)
	{
		fprintf(stderr,"How to use: %s file\n", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}
	printf("%-4s %-8s %-8s %-4s %-4s\n", "id", "name", "category", "expired date", "stock");
	while(scanf("%d %s %s %d %d", &record.id, record.name, record.category, &record.expire, &record.stock) == 5)
	{
		write(fd, (char *) &record, sizeof(record));
	}
	close(fd);
	exit(0);
}
