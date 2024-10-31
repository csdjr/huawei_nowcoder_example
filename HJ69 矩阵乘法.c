#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int a[1000][1000];
	int b[1000][1000];
	int c[1000][1000];
	int x, y, z;
	int i, j,k;

	while (scanf("%d %d %d", &x, &y, &z) != EOF)
	{
		memset(c,0,sizeof(c));

		for(i=0;i<x;i++)
			for (j = 0; j < y; j++)
				scanf("%d",&a[i][j]);

		for (i = 0; i < y; i++)
			for (j = 0; j < z; j++)
				scanf("%d", &b[i][j]);

		for (i = 0; i < x; i++)
			for (j = 0; j < z; j++)
			{
				for (k = 0; k < y; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < z; j++)
			{
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}
	}
}