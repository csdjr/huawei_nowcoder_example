#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[5000];
	int len;
	int i,j;
	char c;
	
	while (gets(str))
	{
		len = strlen(str);
		for (i = 0,j = len - 1; i < j; i++, j--)
		{
			c = str[i];
			str[i] = str[j];
			str[j] = c;
		}

		printf("%s\n",str);
	}
}