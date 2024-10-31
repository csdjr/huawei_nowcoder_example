#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str1[101];
	char str2[9];
	int len;
	int i, j;

	while (gets(str1))
	{
		len = strlen(str1);
		for (i = 0, j = 0; i < len; i++)
		{
			str2[j++] = str1[i];
			if (j == 8)
			{
				str2[j] = '\0';
				printf("%s\n", str2);
				j = 0;
			}
		}
		if (j % 8 != 0)
		{
			while (j % 8 != 0)
			{
				str2[j++] = '0';
			}
			str2[j++] = '\0';
			printf("%s\n", str2);
		}
	}
}