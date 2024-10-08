#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINES 5

char line[MAXLINES][MAXLINE];
char longest[MAXLINE];

main()
{
	int max;
	max = 0;

	while(max < MAXLINES && gets(longest)!= NULL)
	{
		copy(longest, line[max]);
		max++;
	}

	for(int i = 0; i < MAXLINES - 1; i++)
	{
		for(int j = 0; j < MAXLINES - 1 ; j++)
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

	for(int i = 0; i<MAXLINES; i++)
	{
		printf("%s\n", line[i]);
	}

	return 0;
}
