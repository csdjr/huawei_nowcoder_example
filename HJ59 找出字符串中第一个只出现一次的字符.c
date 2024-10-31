#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int flag[128];
	char str[1000];
	int i, len;
	while (gets(str))
	{
		memset(flag,0,sizeof(flag));
		len = strlen(str);
		for (i = 0; i < len; i++)
			flag[str[i]]++;
		for(i=0;i<len;i++)
			if (flag[str[i]] == 1)
			{
				printf("%c\n",str[i]);
				break;
			}
		if (i >= len)
			printf("-1\n");
	}
}