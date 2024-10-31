#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int min3(int a, int b, int c)
{
	a = a <= b ? a : b;
	a = a <= c ? a : c;
	return a;
}

int main()
{
	char str1[1000],str2[1000];
	int len1,len2;
	int dp[1001][1001];
	int i,j;
	while (gets(str1))
	{
		gets(str2);
	
		memset(dp,0,sizeof(dp));

		len1 = strlen(str1);
		len2 = strlen(str2);
		for (i = 0; i <= len1; i++)
			dp[i][0] = i;
		for (j = 0; j <= len2; j++)
			dp[0][j] = j;
		for(i=1;i<=len1;i++)
			for (j =1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min3(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1;
			}
		printf("%d\n",dp[len1][len2]);

	}
}