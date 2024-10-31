#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int main()
{
	int m, n;
	int dp[1000][1000];
	int i, j;


	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(dp,0,sizeof(dp));

		for (i = 0; i <= n; i++)
			dp[i][0] = 1;
		for (j = 0; j <= m; j++)
			dp[0][j] = 1;
		for(i=1;i<=n;i++)
			for (j = 1; j <= m; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}

		printf("%d\n",dp[n][m]);
	}
}