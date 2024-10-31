#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n;
	int num[5000];
	int dp1[5000];
	int dp2[5000];
	int i, j;
	int max;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
			dp1[i] = 1;
			dp2[i] = 1;
		}

		for (i = 0; i < n; i++)
			for (j = 0; j < i; j++)
			{
				if (num[i] > num[j] && dp1[i] < dp1[j] + 1)
					dp1[i] = dp1[j] + 1;
			}

		for(i=n-1;i>=0;i--)
			for (j = n - 1; j > i; j--)
			{
				if (num[i] > num[j] && dp2[i] < dp2[j] + 1)
					dp2[i] = dp2[j] + 1;
			}
		
		max = 0;
		for (i = 0; i < n; i++)
		{
			dp1[i] += dp2[i];
			max = max >= dp1[i] ? max : dp1[i];
		}

		printf("%d\n", n - max + 1);
	}
}