#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[5000];
	int len;
	int i, j;
	int start, end;
	int flag;
	int isFirst;
	while (gets(str))
	{
		flag = 0;
		isFirst = 1;
		len = strlen(str);
		for (i = len - 1; i >= 0; i--)
		{
			if (isalpha(str[i]))
			{
				if (flag == 0)
				{
					end = i;
					flag = 1;
					str[i + 1] = '\0';
				}
			}
			else
			{
				if (flag == 1)
				{
					start = i + 1;
					flag = 0;
					if (isFirst == 0)
						printf(" ");
					else
						isFirst = 0;
					printf("%s",str+start);
				}
			}
		}
		if(isalpha(str[0]))
		{ 
			if (isFirst == 0)
				printf(" ");
			else
				isFirst = 0;
			printf("%s", str);
		}
		printf("\n");
	}
}