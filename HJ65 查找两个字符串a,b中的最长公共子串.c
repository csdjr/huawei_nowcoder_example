#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str1[1000], str2[1000];
	int len1, len2;
	int i, j;
	int dp[1001][1001];
	char* p1, * p2;
	int tmp;
	int start, max;

	while (gets(str1) && gets(str2))
	{
		start = 0;
		max = 0;
		memset(dp,0,sizeof(dp));

		len1 = strlen(str1);
		len2 = strlen(str2);
		
		if (len1 > len2)
		{
			tmp = len1;
			len1 = len2;
			len2 = tmp;
			p1 = str2;
			p2 = str1;
		}
		else
		{
			p1 = str1;
			p2 = str2;
		}

		for(i=1;i<=len1;i++)
			for (j = 1; j <= len2; j++)
			{
				if (p1[i - 1] == p2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (max < dp[i][j])
					{
						max = dp[i][j];
						start = i - max;
					}
				}
				else
					dp[i][j] = 0;
			}
		p1[start + max] = '\0';
		printf("%s\n", p1 + start);
	}
}