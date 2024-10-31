#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int dp[1000][1000];
	int i, j;
	char str1[1000], str2[1000];
	int len1, len2;
	int max;

	while (gets(str1) && gets(str2))
	{
		max = 0;
		memset(dp,0,sizeof(dp));

		len1 = strlen(str1);
		len2 = strlen(str2);

		for(i=1;i<=len1;i++)
			for (j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					max = max >= dp[i][j] ? max : dp[i][j];
				}
				else
					dp[i][j] = 0;
			}
		printf("%d\n",max);
	}
}