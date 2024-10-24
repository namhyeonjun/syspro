#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[2];

	if(argc != 2)
	{
		fprintf(stderr, "How to use :line Filename\n");
		exit(1);
	}
	if((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error Open File\n");
		exit(2);
	}
	while(fgets(buffer,2,fp) != NULL)
	{
		printf("%s", buffer);
	}
	exit(0);
}
