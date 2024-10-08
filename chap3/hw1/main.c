#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINES 100

char line[MAXLINES][MAXLINE];
char longest[MAXLINE];

main()
{
	int max;
	max = 0;

	while(gets(longest) != NULL && max < MAXLINES)
	{
		copy(longest, line[max]);
		max++;
	}

	for(int i = 0; i < max - 1; i++)
	{
		for(int j = 0; j < max -1 ; j++)
		{
			if(strlen(line[j]) < strlen(line[j + 1]))
			{
				char temp[MAXLINE];
				copy(line[j], temp);
				copy(line[j+1], line[j]);
				copy(temp, line[j+1]);
			}
		}
	}

	for(int i = 0; i<max; i++)
	{
		printf("%s\n", line[i]);
	}

	return 0;
}
