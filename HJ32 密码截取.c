#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[5000];
	int len;
	char dp[5000][5000];
	int i, j;
	int max;

	while (gets(str))
	{
		memset(dp, 0, sizeof(dp));

		max = 0;
		len = strlen(str);
		for (i = 1; i <= len; i++)
			for (j = 0; j + i - 1 < len; j++)
			{
				dp[j][j + i - 1] = (i == 1) ||
								   (((i == 2) || dp[j + 1][j + i - 2]) && str[j] == str[j + i - 1]);
				if (dp[j][j + i - 1])
				{
					max = max >= i ? max : i;
				}
			}
		printf("%d\n", max);
	}
}