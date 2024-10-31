#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	float luodi, fantan;
	float num;
	while (scanf("%f", &num) != EOF)
	{
		luodi = num;
		for (int i = 2; i <= 5; i++)
		{
			luodi = luodi + num;
			num = num / 2;
		}
		printf("%.3f\n%.5f\n", luodi, num / 2);
	}
}