#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1, n2;
	int* n;
	int i,j;
	int temp;
	while (scanf("%d %d", &n1, &n2) != EOF)
	{
		n = (int*)malloc(sizeof(int) * n1);
		for (i = 0; i < n1; i++)
		{
			scanf("%d", &n[i]);
		}
		for(i=0;i<n1-1;i++)
			for (j = 0; j < n1 - 1 - i; j++)
			{
				if (n[j] > n[j + 1])
				{
					temp = n[j];
					n[j] = n[j + 1];
					n[j + 1] = temp;
				}
			}
		for (i = 0; i < n2; i++)
		{
			printf("%d",n[i]);
			if (i < n2)
				printf(" ");
		}

		printf("\n");

		free(n);
	}
}