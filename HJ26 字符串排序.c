#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str1[1000], str2[1000];
	int len1, len2;
	int i,j;
	char c;

	while (gets(str1))
	{
		memset(str2, 0, sizeof(str2));

		len1 = strlen(str1);
		for (i = 0,j=0; i < len1; i++)
		{
			if (isalpha(str1[i]))
			{
				str2[j++] = str1[i];
			}
		}
		
		len2 = strlen(str2);
		for(i=0;i<len2-1;i++)
			for (j = 0; j < len2 - 1 - i; j++)
			{
				if (tolower(str2[j]) > tolower(str2[j + 1]))
				{
					c = str2[j];
					str2[j] = str2[j + 1];
					str2[j + 1] = c;
				}
			}

		for(i=0,j =0;i<len1;i++)
			if (isalpha(str1[i]))
				str1[i] = str2[j++];

		printf("%s\n",str1);
	}
}