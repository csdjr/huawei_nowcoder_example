#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int i,j;
	int count;
	while (scanf("%d", &N) != EOF)
	{
		count = 0;
		for (i = 1; i <= N; i++)
		{
			j = i;
			if (j % 7 == 0)
			{
				count++;
				continue;
			}
			while (j > 0)
			{
				if (j % 10 == 7)
				{
					count++;
					break;
				}
				else
					j = j / 10;
			}
		}
		printf("%d\n",count);
	}
}