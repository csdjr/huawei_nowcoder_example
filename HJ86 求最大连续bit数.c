#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int c;
	int max;
	int n;

	while (scanf("%d", &c) != EOF)
	{
		n = 0;
		max = 0;
		while (c != 0)
		{
			if (c % 2 == 1)
			{
				n++;
				max = max >= n ? max : n;
			}
			else
				n = 0;
			c = c / 2;
		}

		printf("%d\n",max);
	}
}