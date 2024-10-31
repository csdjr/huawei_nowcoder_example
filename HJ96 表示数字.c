#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str1[5000], str2[5000];
	int len;
	int i,j,k;
	int flag;
	char* p;

	while (gets(str1))
	{
		len = strlen(str1);
		for (i = 0, j = 0; i < len; )
		{
			if (!isdigit(str1[i]))
				str2[j++] = str1[i++];
			else
			{
				str2[j++] = '*';
				strtoul(str1 + i, &p,10);
				k =p - str1 - 1;
				for (; i <= k;)
					str2[j++] = str1[i++];
				str2[j++] = '*';
			}
		}
		str2[j] = '\0';
		printf("%s\n",str2);
	}
}