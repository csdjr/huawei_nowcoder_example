#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
	int num;
	int i;
	while(scanf("%d", &num) != EOF)
	{
		for (i = 2; i <= num; )
		{
			if (num % i == 0)
			{
				printf("%d ", i);
				num = num / i;
			}
			else
				i++;
		}
		printf("\n");
	}
}