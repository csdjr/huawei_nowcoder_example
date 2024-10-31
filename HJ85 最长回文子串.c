#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[1000];
	char dp[1000][1000];
	int i, j;
	int len;
	int max;

	while (gets(str))
	{
		max = 0;
		memset(dp,0,sizeof(dp));
		
		len = strlen(str);

		for(i=1;i<=len;i++)
			for (j = 0; j + i - 1 < len; j++)
			{
				dp[j][j + i - 1] = (i == 1) || ((i == 2 || dp[j + 1][j + i - 2]) && str[j] == str[j + i - 1]);
				if (dp[j][j + i - 1])
				{
					max = max >= i ? max : i;
				}
			}
		printf("%d\n",max);
	}
}