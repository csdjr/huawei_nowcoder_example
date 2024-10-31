#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int m;
	int n1, n2, n3;

	while (scanf("%d", &m) != EOF)
	{
		n1 = 1;
		n2 = 0;
		n3 = 0;
		while (m > 1)
		{
			n3 = n3 + n2;
			n2 = n1;
			n1 = n3;
			m--;
		}
		printf("%d\n", n1 + n2 + n3);
	}
}
