#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[501];
	char c;
	int len;
	int flag[256];
	int i;

	while (gets(str))
	{
		scanf("%c",&c);
        		getchar();
        
		memset(flag,0,sizeof(flag));

		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			flag[tolower(str[i])]++;
		}

		printf("%d\n",flag[tolower(c)]);
	}

}