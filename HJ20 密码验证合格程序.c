#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	char str[100];
	int len;
	int isUp, isLow, isfigure, isother;
	int i,j;
	int chongfu;

	while (scanf("%s", str) != EOF)
	{
		chongfu = 0;

		len = strlen(str);
		if (len < 9)
		{
			printf("NG\n");
			continue;
		}
		
		isUp = 0; 
		isLow = 0;
		isfigure = 0;
		isother = 0;

		for (i = 0; i < len; i++)
		{
			if (isupper(str[i]))
				isUp = 1;
			else if (islower(str[i]))
				isLow = 1;
			else if (isdigit(str[i]))
				isfigure = 1;
			else
				isother = 1;
		}
		if (isUp + isLow + isfigure + isother < 3)
		{
			printf("NG\n");
			continue;
		}

		for(i=0;i<len-3 && chongfu==0;i++)
			for (j = i + 1; j < len-2; j++)
			{
				if(str[i] == str[j] && str[i+1] == str[j+1] && str[i+2] == str[j+2] )
				{
					chongfu = 1;
					break;
				}
			}
		if(chongfu == 1)
			printf("NG\n");
		else
		printf("OK\n");
	}
}