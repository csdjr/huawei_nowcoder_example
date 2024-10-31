#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str1[21];
	int len1;
	int i;
	int flag[128];
	int min;

	while (scanf("%s", str1) != EOF)
	{
		min = 21;
		memset(flag,0,sizeof(flag));
		len1 = strlen(str1);
		for (i = 0; i < len1; i++)
			flag[str1[i]]++;
		for (i = 0; i < 128; i++)
			if (min > flag[i] && flag[i] != 0)
				min = flag[i];
		for (i = 0; i < len1; i++)
			if (flag[str1[i]] != min)
				printf("%c",str1[i]);
		printf("\n");
	}
}