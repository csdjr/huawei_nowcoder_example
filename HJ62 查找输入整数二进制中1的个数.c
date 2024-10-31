#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int count;

	while (scanf("%d", &n) != EOF)
	{
		count = 0;
		while (n != 0)
		{
			if (n % 2 == 1)
				count++;
			n = n / 2;
		}
		printf("%d\n", count);
	}
}