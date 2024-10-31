#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[5000], str2[5000];
	int len1, len2;
	int flag[128];
	int i;

	while (gets(str1) && gets(str2))
	{
		memset(flag,0,sizeof(flag));
		
		len1 = strlen(str1);
		len2 = strlen(str2);

		for (i = 0; i < len2; i++)
			flag[str2[i]]++;

		for (i = 0; i < len1; i++)
			if (flag[str1[i]] == 0)
				break;

		if (i >= len1)
			printf("true\n");
		else
			printf("false\n");
	}
}