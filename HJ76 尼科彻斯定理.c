#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	int i;

	while (scanf("%d", &n) != EOF)
	{
		for (i = n * (n - 1) + 1; i <= n * (n + 1) - 1; i = i + 2)
		{
			printf("%d", i);
			if (i != n * (n + 1) - 1)
				printf("+");
			else
				printf("\n");
		}
	}
}