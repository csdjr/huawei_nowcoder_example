#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n1, n2,n3;
	int x, y,z;

	while (scanf("%d %d", &n1, &n2) != EOF)
	{
		if (n1 >= n2)
		{
			x = n1;
			y = n2;
		}
		else
		{
			x = n2;
			y = n1;
		}
		z = 1;

		while (y != 0)
		{
			z = x % y;
			x = y;
			y = z;
		}

		printf("%d\n",n1*n2/x);
	}
}