#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int m[10];
	int x[10];
	int max, count;
	int i, j, k;
	char *flag;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &m[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &x[i]);
		max = 0;
		count = 0;
		for (i = 0; i < n; i++)
			max = max + m[i] * x[i];
		flag = (char *)malloc(max + 1);
		memset(flag, 0, max + 1);
		flag[0] = '1';
		for (i = 0; i < n; i++)		   // i是砝码
			for (j = max; j >= 0; j--) // j是重量
			{
				if (flag[j] == '1')
				{
					for (k = 1; k <= x[i]; k++) // k是选择第i个砝码的个数
						flag[j + k * m[i]] = '1';
				}
			}
		for (i = 0; i <= max; i++)
			if (flag[i] == '1')
				count++;
		printf("%d\n", count);
		free(flag);
	}
}