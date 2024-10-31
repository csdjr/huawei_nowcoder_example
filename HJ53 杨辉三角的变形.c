#include <stdio.h>
#include <stdlib.h>

int main()
{

	char** num;
	int n;
	int i, j;

	while (scanf("%d", &n) != EOF)
	{
		if (n <= 2)
		{
			printf("-1\n");
			continue;
		}
		if (n == 3)
		{
			printf("2\n");
			continue;
		}

		num = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++)
			num[i] = (char*)malloc((i + 1) * sizeof(char));

		num[0][0] = 1;
		num[1][0] = 1; num[1][1] = 1;
		num[2][0] = 1; num[2][1] = 0; num[2][2] = 1;
		for(i=3;i<n;i++)
			for (j = 0; j < i + 1; j++)
			{
				if (j == 0)
					num[i][0] = 1;
				else if (j == 1)
					num[i][1] = (1 + num[i - 1][1]) % 2;
				else if (j == i)
					num[i][j] = num[i - 1][j - 1];
				else
					num[i][j] = (num[i - 1][j] + num[i - 1][j - 1] + num[i - 1][j - 2]) % 2;
			}

		for (j = 0; j < n; j++)
			if (num[n - 1][j] == 0)
				break;
		if (j < n)
			printf("%d\n", j + 1);
		else
			printf("%d\n", -1);

		for (i = 0; i < n; i++)
			free(num[i]);
		free(num);
	}
}