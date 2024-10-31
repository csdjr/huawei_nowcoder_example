#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int num;
	int fushu=0, pingjunshu=0,pingjunshucount=0;
	while (scanf("%d", &num) != EOF)
	{
		if (num < 0)
			fushu++;
		else
		{
			pingjunshu += num;
			pingjunshucount++;
		}
	}
	printf("%d\n%.1f\n", fushu, pingjunshu *1.0 / pingjunshucount);
}