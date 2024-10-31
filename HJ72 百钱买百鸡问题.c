#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int i, j, k;
	int maxi, maxj, maxk;

	while (scanf("%d", &n) != EOF)
	{
		maxi = 100 / 5;
		maxj = 100 / 3;
		maxk = 100;

		for(i=0;i<=maxi;i++)
			for(j=0;j<=maxj;j++)
				for (k = 0; k <=maxk; k++)
				{
					if (i + j + 3 * k == 100 && 5 * i + 3 * j + k == 100)
						printf("%d %d %d\n", i, j, k*3);
				}
	}
}