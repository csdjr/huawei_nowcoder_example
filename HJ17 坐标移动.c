#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid(char* p)
{
	int len = strlen(p);
	if (len > 3 || len<2)
		return -1;
	if (*p != 'A' && *p != 'D' && *p != 'W' && *p != 'S')
		return -1;
	if (!isdigit(*(p + 1)))
		return -1;
	if (len == 3 && !isdigit(*(p + 2)))
		return -1;
	return 1;
}

int main()
{
	int  num1, num2,num3;
	char str[5000];
	char* p;
	int validResult;
	while (gets(str))
	{
		num1 = 0;
		num2 = 0;
		p = strtok(str,";");
		while (p != NULL)
		{
			validResult = valid(p);
			if (validResult > 0)
			{
				num3 = strtoul(p + 1,NULL,10);
				switch (*p)
				{
				case 'A':num1 = num1 - num3; break;
				case 'D':num1 = num1 + num3; break;
				case 'S':num2 = num2 - num3; break;
				case 'W':num2 = num2 + num3; break;
				}
			}
			p = strtok(NULL,";");
		}
		printf("%d,%d\n",num1,num2);
	}
}