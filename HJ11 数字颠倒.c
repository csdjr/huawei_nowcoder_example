#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	while (scanf("%d", &num) != EOF)
	{
		while (num != 0)
		{
			printf("%d", num % 10);;
			num = num / 10;
		}
		printf("\n");
	}
}
